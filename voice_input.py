import speech_recognition as sr

recognizer = sr.Recognizer()
with sr.Microphone() as source:
    print("Listening...")
    audio = recognizer.listen(source)

try:
    text = recognizer.recognize_google(audio)
    print(text)
except sr.UnknownValueError:
    print("Could not understand")
except sr.RequestError:
    print("Request error")
