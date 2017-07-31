### DESCRIPTION
This is my final project for my CNIT 361 - Workstation and Server course.  We were told to take a script we already wrote and expand it a little bit.  I wanted a bigger challenge so I made it harder.

### SCENERIO
A small educational organization has an HR department and Active Directory to manage log ins.  The HR software is not compatiable with Active Directory.  Both the HR and IT teams were adding new students in their own respective software applications.  The organization was growing larger and had many mismatches of information between the two systems.  The IT team found out that HR can export a list of new users via *.csv so they decided to make a script to automatically import them.

### SAMPLE CSV
```
FirstName,LastName,Address,HomePhone,MobilePhone,Job,Email
John,Smith,"123 Pine Street New York, NY",111-111-1111,111-111-0000,Student,smith@yahoo.com
Jane,Doe,"456 Oak Avenue Madison, WI",222-222-2222,222-222-0000,Student,bambi@gmail.com
Bruce,Wayne,"789 Cave Street Los Angelos, CA",333-333-3333,333-333-0000,Student,iambatman@batlovers.com
George,Washington,"111 Independence Ave Washington, DC",444-444-4444,444-444-0000,Student,britishsuck@patriots.com
```

### SCRIPT
```
##################################################################################
##	Automatically Add Students from Exported CSV from HR ERP Software
##		Author: First Last
##			Rev: 1.0
##
##		1.0 Changes
##			Initial Write
##
##################################################################################

#Make sure the ActiveDirectory module is imported
Import-Module ActiveDirectory

#Create OU and Group.  REQUIRED FOR LAB ENVIRONMENT. NOT NEEDED FOR PRODUCTION ENVIRONMENT
New-AdGroup -Name Students -GroupScope 1
New-AdOrganizationalUnit -Name Students

#Load the NewStudents file.  CSV MUST BE IN SAME DIRECTORY AS SCRIPT.  Pipe to create new user for every line in CSV
Import-Csv "NewStudents.csv" | ForEach-Object {

#Set variables
 $name = $_."FirstName" + $_."LastName"

New-AdUser -Name $name `
-GivenName $_."FirstName" `
-Surname $_."LastName" `
-Path 'OU=Students,DC=adatum,DC=com' `
-SamAccountName $name `
-EmailAddress $_."Email" `
-StreetAddress $_."Address" `
-HomePhone $_."HomePhone" `
-MobilePhone $_."MobilePhone" `
-Title $_."Job" `
-AccountPassword (ConvertTo-SecureString -AsPlainText "Pa$$w0rd123" -Force) `
-ChangePasswordAtLogon $true `
-Enabled $true `

Add-ADGroupMember "Students" $name;
}
```
