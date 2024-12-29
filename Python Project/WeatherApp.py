import requests

def get_weather(city):
    
    api_key = "b5b0a3cfc7827eb6e9fd97faa7103bcb"
    base_url = "http://api.openweathermap.org/data/2.5/weather"
    
    params = {
        "q": city,
        "appid": api_key,
        "units": "metric"  
    }
    
    try:
        response = requests.get(base_url, params=params)
        response.raise_for_status()  
        weather_data = response.json()

        city_name = weather_data["name"]
        temperature = weather_data["main"]["temp"]
        description = weather_data["weather"][0]["description"]

        print(f"Weather in {city_name}:")
        print(f"Temperature: {temperature}°C")
        print(f"Description: {description.capitalize()}")
    except requests.exceptions.RequestException as e:
        print(f"Error fetching weather data: {e}")
    except KeyError:
        print("City not found or invalid response.")

if __name__ == "__main__":
    print("Welcome to the Simple Weather App!")
    while True:
        city = input("Enter a city name (or type 'q' to quit): ")
        if city.lower() == "q":
            print("Goodbye!")
            break
        get_weather(city)
