![Banner](img/logo1.png)  
# STILL IN DEVELOPMENT! All builds are in beta testing.

# All-In-One Compiler For Windows!
This program simplifies compiling files from the command line by automatically choosing which compiler to use. Compiling from CMD has never been so easy! compile is written in C++ and can be tweaked if needed.
# Requirements
- PC running 64-bit Windows (have not tested 32-bit yet...)
- Microsoft Visual C++ Redistributable 2015-2022 (maybe?)
# Setup (Recommended)
Install the `compile-install.exe` file from the [latest installer release](https://github.com/HudsonGageTaylor/compile/releases/latest) and run it. Confirm the installation and you're good to go! The `compile.exe` file, `MinGW` folder, and the `.cargo` folder will be in `C:\compile\` and will automatically be added to PATH. If this doesn't work, try the [outdated method](#setup-outdated)  
# Usage

Syntax: pile \<source_file\> as \<output_name_without_exe\>

### Languages supported (from v1.1):
C++ (.cpp)  
C (.c)  
Rust (.rs)  
Fortran (.f, .for, .ftn, .f77, .f90, .f95, .f03, .f08, .f18)  
  
**More coming soon!**
# Setup (OUTDATED!)
If you don't want to use the installer for some reason, this method is for you.
### MinGW Setup
Download the official minimalist .exe [from here.](https://sourceforge.net/projects/mingw/files/latest/download)  Proceed with the installation until you get an install screen similar to this:  
  
![Banner](img/screen1.jpg)  

Then select these tools for installation:  
  
**mingw32-base**  
**mingw32-gcc-fortran**  
**mingw32-gcc-g++**  

Once done, hit install and wait!  

Once the installation is finished, go to the Windows search bar and type "Environment Variables" and select **Edit the system environment variables.**  
You should get a screen like this:  

![Banner](img/screen2.png)  

Click the button that says **"Environment Variables..."** and a new window should appear. In the lower box which says "System variables", double click "Path":   
  
![Banner](img/screen3.png)  
  
Press the **"New"** button and add this into the prompt: `C:\MinGW\bin`. It should look like this:  
    
![Banner](img/screen4.png)  
  
***Make sure to hit the "Apply" button in the "System Properties" window!***  

### Rustc Setup
Download the correct rustup .exe for your machine from the [official download page.](https://www.rust-lang.org/tools/install) Run the program and choose the standard installation.  

### compile Setup
Download `compile.exe` from the [latest single release.](https://github.com/HudsonGageTaylor/compile/releases/v1.1) Once finished, place the executable in a folder and add the folder to the PATH (same process as adding minGW to PATH). For example, if you place it in C:\bin:  

![Banner](img/screen5.png)  

Hit "Apply" and your done with the setup!

