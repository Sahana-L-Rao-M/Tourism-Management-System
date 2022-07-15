# Tourism-Management-System
Abstract:
  Tourism Management System Project in C facilitates national and international tourism. The client needs to go through login       framework to get access. Thereafter,the client can utilize the facilities of the program which incorporates functions such as     booking ticket, printing ticket, cancelling ticket, seeing the travel industry handout.

Concepts/Collections/structure Used:
  1.Linked list and pointers
  2.File handling(to record all users,print tickets)

Working:
  Basic concept used is linked list and pointers.
  This program contains the following files: 
    Main.c : This contains the working code-client and server which consists all the basic functions like initialising list,adding new user,logging in to existing user account,viewing tourism brochure,booking ticket,printing ticket,deleting ticket.
    details_of_packages.c : This file contains all the information and details of various packages and their attributes like duration of each destination,per person cost and places of visit under that package.
    header.h : Contains all declarations and structure called userprofile(with data like name,password etc)
    make.mk : Make file to handle multiple files

Expected outcome:
  1.Login-Sign up framework using username and masked password.
  2.View travel brochure
  3.Book tickets
  4.View / Print Booked tickets
  5.Cancel ticket
  
Modules Used:
  Standard files(C preprocessor #include directive) and user-defined files(header file)
  
HOW TO RUN THE FILES?

  In Windows:
    Open the terminal and in the command-line:
    
        mingw32-make -f make.mk
        
        a.exe
