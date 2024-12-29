import face_recognition  # Correct module name
import cv2
import numpy as np
import csv
from datetime import datetime

video_capture = cv2.VideoCapture(0)

# Load known faces
harrys_image = face_recognition.load_image_file("faces/harry.jpg")
harry_encoding = face_recognition.face_encodings(harrys_image)[0]

monjurs_image = face_recognition.load_image_file("faces/monjur.jpg")
monjur_encoding = face_recognition.face_encodings(monjurs_image)[0] 

known_face_encodings = [harry_encoding, monjur_encoding]
known_face_names = ["Harry", "Monjur"]

# List of expected students
students = known_face_names.copy()

face_locations = []
face_encodings = []

now = datetime.now()
current_date = now.strftime("%Y-%m-%d")

f = open(f"{current_date}.csv", "w+", newline="")
lnwrite = csv.writer(f)

while True:
    _, frame = video_capture.read()
    small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
    rgb_small_frame = cv2.cvtColor(small_frame, cv2.COLOR_BGR2RGB)  # Fix color conversion

    face_locations = face_recognition.face_locations(rgb_small_frame)
    face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

    for face_encoding in face_encodings:
        matches = face_recognition.compare_faces(known_face_encodings, face_encoding)
        face_distance = face_recognition.face_distance(known_face_encodings, face_encoding)
        best_match_index = np.argmin(face_distance)

        if matches[best_match_index]:
            name = known_face_names[best_match_index]

        if name in known_face_names:
            font = cv2.FONT_HERSHEY_COMPLEX
            bottom_left_corner = (10, 100)
            font_scale = 1.5
            font_color = (255, 0, 0)  # Fix font color assignment
            thickness = 3
            line_type = 2  # Fix typo

            # Add text on the frame
            cv2.putText(frame, name + " Present", bottom_left_corner, font, font_scale, font_color, thickness, line_type)
            cv2.imshow("Attendance", frame)
            
            # Save attendance to CSV
            lnwrite.writerow([name, current_date, "Present"])

    # Exit loop with 'q' key
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

video_capture.release()
cv2.destroyAllWindows()
