# RHPC-Simulator

# Introduction

## Authors

- Jinwook Kim (Main)
- Soumik Sarkar (Support)

## Note

- Please remember to pull, before you start to make changes as this is an in-dev project, which constantly gets commits pushed to the branch.
- There is just one branch in this project.
- **Please perform CMake before opening the solution file.**

## Support Ticket

- Please go to RH Operations Group in Microsoft Teams and Control Lab activities sub-branch.
- In section "RHPC-Simulator-Support Tickets", make a ticket, with requirement topic name, end date, and assign it to the support guy.

## Scope

- Make a Simulated Device to be detected by Remote Handling Plant Controller HMI
- The GUI gives the ability to assign several devices (technically 100), to different rooms represented in the RHPC HMI.

## Pre-installed stuff you need!

- Install the latest version of Qt. We use Qt Community Version
- Install the latest version of Visual Studio. We use Visual Studio Community Version
- Install Visual Studio Code (if you need)
- Install CMake, the latest version (remember to update the cmake version in all the CMakeLists.txt)

## Libraries needed

- Qt
- CDN API
- Standard C++ libraries
- Custom Libs added by devs

# Building this project

## For Visual Studio + CMake : Windows

Please follow the step below to build and execute this project in Visual Studio

- Open CMake GUI
- Select the project folder as Source Folder (Where is the source)
- Select the build folder as the Build Folder (Where is the build folder)
- Click on "Configure", select the compiler as the latest version of Visual Studio installed on your PC...
- If configuration done successfully, click on "Generate"..
- If generating done successfully, click on "Open Project"
- Now the generated solution file should open in Visual Studio.
- Go under "Main" in the "Solution Explorer"
- There you should see the main GUI sub project.
- For the other independent libraries, they are outside the "Main" branch.
- Now, based on your case, do the following:
    - First build: 
        - Right Click on top most solution in the Solution Explorer and select "build solution"
        - Once built successfully, go to the GUI sub project, Right Click -> Debug -> Start a New Instance
    - Edit files + test
        - You can either go to the GUI sub project, Right Click -> Debug -> Start a New Instance, which would build the project (and show you the errors in case you have errors)
        - or you can build entire solution and then Start a New Instance, which will automatically skip the files which you have not modified since last build.
    - Rebuild Solution / Rebuild Project
        - This option will clean the previous build generated files (could be interesting in case you need to debug from the start..)


## For Visual Studio Code Execution : Windows

Please check if you have done the following, (or feel free to change these settings as you want for yourself!)

- Make sure you have installed the following: 
    - Visual Studio (VS)
    - Visual Studio Code (vscode) 
    - CMake
- If you use any other compiler or another OS, these steps are not for you!!
- Go to control panel and search "Path Variable"
- Edit Environment Variable for your account (if you do not have admin rights)
- Select "Path" and click on "Edit".
- Add a new path to an executable called MSBuild.exe, that should be present after the installation of VS.
- The path to MSBuild.exe would look like: "C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin"
- Then, you should find the path to your Qt includes: "C:\Qt\6.4.0\msvc2019_64\include"
- If you need, add the path to cl.exe, but not needed for now..
- Go to c_cpp_properties.json which is in .vscode folder and check that the includePath to Qt includes is the good one...
- Open the folder in vscode.
- Open a powershell terminal in vscode.
- If a build folder exists, go `cd build` or else create a build folder `mkdir build` and then `cd build`
- type `cmake ..` and press enter.
- Check the message showing "Configuring done" and "Generating Done"
- Open another powershell terminal is you prefer or in the same, type `msbuild .\Your_Project_Name.sln` and press enter.
- If there are no errors, it would show in green Build succeeded, 0 Warning(s) and 0 Error(s).
- If there are errors, it would show you the errors, fix them!
- Open another powershell termninal (second one or third one, depending on how many you opened before..)
- Go to `cd build/bin/Debug`
- Make sure you have copied the files of "build_support" into this folder. If not, do this now!
- Type ```./Name_Of_Your_Executable.exe```
- You should see your output...

## For Visual Studio Code Execution : Red Hat Enterprise Linux 7.0

To be updated in the future after testing!!