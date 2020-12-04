 # Project: General Hospital Pre-Triage Application

Because of the pandemic and prevention of the spread of COVID19, hospitals need to screen the patients and separate those in need of COVID-test from others. This has to be done in an orderly fashion by letting the patients know what is the expected wait time and let them know when they can be admitted. 

Your task is to help complete the implementation of the Pre-Triage application. 

## The Pre-Triage Application
The application starts by displaying a simple menu with three options:
```Text
General Hospital Pre-Triage Application
1- Register
2- Admit
0- Exit
>
```
### Register
The register option is selected to screen patients before getting into the hospital. The user can select between a COVID Test or Triage.

COVID test is selected if the patient is at the hospital for a COVID Test. In this case, the patient's name and OHIP number is entered and then a ticket will be printed with a call number and estimated time of admission for the patient.

If Triage is selected then in addition to the patient's name and OHIP number, the symptoms of the patient are entered. Then a ticket for Triage is printed with an estimated time of admission.

### Admit
Admit is selected when the COVID Test area or the Triage section is ready to accept a patient. After selecting COVID or Triage, the patient with the next ticket in line will be called. Based on the time of the call, the average wait time for the next patient for that line up (COVID or Triage) will be updated.





## fpTester.cpp 

The fpTester program will be copied from the professor's directory to yours and will combine all three testers.

The execution samples will be provided by Monday, Dec 30th.

## MS5 Submission and the due date
Milestone 5 is due on Saturday, Dec 5th, 23:59 for a full mark. 

### Milestone submission marks
15% mark for milestones if they are submitted in the past 4 weeks and not all at once at the end. (no hard due date for ms1 to ms4; OK if submissions are done regularly in the past four weeks)


### Bonus mark (110%)
Early submissions before Dec 4th, 23:59 will get a 10% bonus mark.

### Submitting with non-exact output (10% penalty)
If your submission does not match the output exactly and is different with number of spaces or newlines, you can submit your work using the following options:  
```text
~porfname.proflastname/submit 244/prj/fp -skip_spaces 
or
~porfname.proflastname/submit 244/prj/fp -skip_blank_lines
or both
~porfname.proflastname/submit 244/prj/fp -skip_blank_lines -skip_spaces
```

### Open submission (Maximum 65% for incomplete work)

This submission will not check the output. But the program must compile and run successfully and must be functional.
#### NOTE:
- Submission is rejected if milestones 1 to 4 are not submitted regularly (submissions do not have to match the due-dates exactly)
- The mark is based on the professor’s discretion and a maximum 65% is not a guaranty.
- You must mention in your reflect.txt why you chose open submission.
- You may use open submission after you have done your full submission if you have added additional features and want to demonstrate them for extra marks; make sure to discuss this with your professor and have the details in your reflection submission.


### Submission  (not open yet)

Upload your source code and the tester programs to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):

#### Normal submission
```
~profname.proflastname/submit 244/prj/fp
```
#### Open submission
```
~profname.proflastname/submit 244/prj/open
```
and follow the instructions.


> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
