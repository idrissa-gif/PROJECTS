# ASSIGNMENT4_CSE_4636

Create a StudentBean stateless session bean. This session bean should have several
RESTful endpoints that can do the following:

• Given a student ID, name, semester, and cgpa as query parameters, add a new
student entry with the given values into your backend database.

<img width="1440" alt="Screenshot 2023-04-14 at 15 47 21" src="https://user-images.githubusercontent.com/76502860/232010394-21d902ae-d9e9-40b0-a6a6-f29418490796.png">

ADDED SUCCESSFULLY 

<img width="1440" alt="Screenshot 2023-04-14 at 15 47 46" src="https://user-images.githubusercontent.com/76502860/232010516-2a0d5cde-2460-4789-8269-7b75559d6968.png">
<img width="1440" alt="Screenshot 2023-04-14 at 15 52 49" src="https://user-images.githubusercontent.com/76502860/232011737-ae7e6826-1da5-4749-a70c-6cc4c88b77cb.png">

• Given a student ID as a path parameter, return the name of the student. This information should come from the backend database.

<img width="1440" alt="Screenshot 2023-04-14 at 15 49 23" src="https://user-images.githubusercontent.com/76502860/232010895-186fa74d-30a2-4a3a-9ad6-6f7854f76863.png">
<img width="1440" alt="Screenshot 2023-04-14 at 15 49 33" src="https://user-images.githubusercontent.com/76502860/232010924-a7e54960-6bee-4cc9-bf2e-630fc2f23053.png">
<img width="1440" alt="Screenshot 2023-04-14 at 15 49 47" src="https://user-images.githubusercontent.com/76502860/232010975-c23317dd-e880-485f-9777-8e5476878713.png">


Given the student IDs of 2 different students as query parameters, return the student name, ID, and cgpa of the student who has the higher cgpa. This information should come from the backend database.
<img width="1440" alt="Screenshot 2023-04-14 at 15 50 27" src="https://user-images.githubusercontent.com/76502860/232011117-42a92f26-4837-4798-a38c-e82f22fd5b29.png">

<img width="1440" alt="Screenshot 2023-04-14 at 15 51 20" src="https://user-images.githubusercontent.com/76502860/232011330-0b5031f3-a806-4fc8-bd86-ee1e36a359db.png">

• Given the student ID and name as query parameters, update the name of the student with the name given in the query parameter. This change should be reflected in the backend database.

<img width="1440" alt="Screenshot 2023-04-14 at 15 55 17" src="https://user-images.githubusercontent.com/76502860/232012324-a9b3c117-ce6c-421e-b7e5-e7d6880c5009.png">

<img width="1440" alt="Screenshot 2023-04-14 at 15 55 57" src="https://user-images.githubusercontent.com/76502860/232012495-b217796d-1901-4249-8aa4-38cd7e7f034d.png">

<img width="1440" alt="Screenshot 2023-04-14 at 15 56 46" src="https://user-images.githubusercontent.com/76502860/232012811-394c11f0-c837-4519-b702-cc74cafe7fa5.png">

Create a RESTful endpoint through a singleton session bean that will always return the
name and ID of the student with the highest cgpa. This information should come from
the backend database.

<img width="1440" alt="Screenshot 2023-04-14 at 16 02 50" src="https://user-images.githubusercontent.com/76502860/232014804-4b13bac2-a7f5-4632-ba9f-ede9fb1130df.png">

<img width="1440" alt="Screenshot 2023-04-14 at 16 03 12" src="https://user-images.githubusercontent.com/76502860/232014912-1893fb2e-18f1-410d-95a5-47d7f1c4b398.png">
