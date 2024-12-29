import face_recognition
import cv2
import numpy as np
import csv
from datetime import datetime

video_capture = cv2.VideoCapture(0)

harrys_image = face_recognition.load_image_file("faces/harry.jpg")
harry_encoding = face_recognition.face_encodings(harrys_image)[0]

monjurs_image = face_recognition.load_image_file("faces/monjur.jpg")
monjur_encoding = face_recognition.face_encodings(monjurs_image)[0]

known_face_encodings = [harry_encoding, monjur_encoding]
known_face_names = ["Harry", "Monjur"]

logged_students = set()


now = datetime.now()
current_date = now.strftime("%Y-%m-%d")

with open(f"{current_date}.csv", "w", newline="") as f:
    lnwrite = csv.writer(f)
    lnwrite.writerow(["Name", "Date", "Status"]) 

    while True:
        
        ret, frame = video_capture.read()
        if not ret:
            print("Failed to capture video")
            break

       
        small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
        rgb_small_frame = cv2.cvtColor(small_frame, cv2.COLOR_BGR2RGB)

        
        face_locations = face_recognition.face_locations(rgb_small_frame)
        face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

        for face_encoding, face_location in zip(face_encodings, face_locations):
            matches = face_recognition.compare_faces(known_face_encodings, face_encoding)
            face_distance = face_recognition.face_distance(known_face_encodings, face_encoding)
            best_match_index = np.argmin(face_distance)

            name = "Unknown"
            if matches[best_match_index]:
                name = known_face_names[best_match_index]

            
            if name != "Unknown" and name not in logged_students:
                logged_students.add(name)
                lnwrite.writerow([name, current_date, "Present"])
                print(f"{name} marked as present.")

           
            top, right, bottom, left = [v * 4 for v in face_location]  
            cv2.rectangle(frame, (left, top), (right, bottom), (0, 255, 0), 2)
            cv2.putText(frame, name, (left, top - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (255, 0, 0), 2)

        
        cv2.imshow("Attendance", frame)

        
        if cv2.waitKey(1) & 0xFF == ord("q"):
            print("Exiting the program...")
            break


video_capture.release()
cv2.destroyAllWindows()
