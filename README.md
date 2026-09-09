# \# Beyond-Shell-Growth-Temporal-Evolution-of-the-Au-Ag-core-shell

# 

# This repository contains modified simulation codes and workflows to study the temporal evolution of \*\*Au@Ag core@shell nanoparticles\*\*. Instead of generating data for a single wavelength, this modified suite automates \*\*ADDA\*\* to produce a complete \*\*300 nm to 700 nm spectrum\*\*, while organizing all outputs dynamically based on structural dimensions (in Angstroms).

# 

# \---

# 

# \## 🛠️ Installation \& Setup Instructions

# 

# Follow these steps sequentially to set up the patched ADDA environment and run the simulations.

# 

# \### Step 1: Download \& Patch ADDA

# 1\. Download the original \*\*ADDA source code\*\* (ZIP file) from GitHub and extract it.

# 2\. Navigate to the `src/` directory of the original ADDA folder.

# 3\. Locate the `files to be replaced in src` folder in this repository, and copy its \*\*4 modified files\*\* into the original ADDA `src/` directory (replace the existing files when prompted).

# 

# \### Step 2: Compile ADDA (`make seq`)

# 1\. Open your Ubuntu terminal inside the ADDA root directory.

# 2\. Run the compilation command to build the sequential version of ADDA:

# &#x20;  ```bash

# &#x20;  make seq

# &#x20;  ```

# &#x20;  \*(This technical step compiles the source code into a sequential executable).\*

# 

# \### Step 3: Copy Refractive Index Data

# 1\. Go to the `files to be copy paste inside seq\_refractive index` folder in this repository.

# 2\. Copy the wavelength-dependent complex refractive index files for \*\*Water, Gold (Au), and Silver (Ag)\*\*.

# 3\. Paste these files directly into the `seq/` folder of your ADDA directory.

# 

# \---

# 

# \## 🚀 Running the Simulations

# 

# \### Step 4: Add Structure Files to `seq/`

# 1\. Choose the specific nanoparticle geometry you want to simulate (e.g., \*tri\_alloy Shell, core\_alloy\_shell, bishell, or bi\_alloy\_shell\*).

# 2\. Copy all the custom \*\*C programs\*\* and the automating \*\*Shell Script (`.sh`)\*\* from that specific structure's folder. 

# &#x20;  \*(Note: The number of C programs varies depending on the specific geometry/structure).\*

# 3\. Paste all of them directly into the ADDA `seq/` directory.

# 

# \### Step 5: Set Permissions \& Run

# Open a terminal inside the `seq/` directory and execute the workflow:

# 1\. \*\*Make the Shell Script executable\*\* (Give permission):

# &#x20;  ```bash

# &#x20;  chmod +x shell\_script\_name.sh

# &#x20;  ```

# 2\. \*\*Execute the Workflow:\*\*

# &#x20;  ```bash

# &#x20;  ./shell\_script\_name.sh

# &#x20;  ```

# \*(Note: The automation shell script will handle the sequential execution of the C programs and ADDA. If your script doesn't compile the C files automatically, ensure you compile them using `gcc program\_name.c -o program\_name -lm` before running the script).\*

# 

# \---

# 

# \## 📊 User Inputs \& Simulation Progress

# 

# Once the script starts, it will prompt you for inputs in the terminal:

# 1\. \*\*Structural Information:\*\* Input the geometric parameters as requested.

# 2\. \*\*Material Selection:\*\* Select the appropriate core/shell materials.

# 3\. \*\*Grid Size Selection (Accuracy):\*\* The user can select the number of grids based on their computational capacity to balance accuracy and runtime.

# 

# After selecting the options, the program will automatically execute sequentially across the \*\*300 nm to 700 nm\*\* wavelength range.

# 

# \---

# 

# \## 📈 Output Files \& Data Structure

# 

# For every standard run, ADDA natively generates 4 primary values: \*\*Qabs, Qext, Cabs, and Cext\*\*. 

# 

# Our custom code intercepts these individual runs, parses the data, and automatically organizes them by wavelength to output \*\*4 consolidated spectrum data files\*\*. You can directly plot these output files to visualize the \*\*300 nm to 700 nm spectra\*\*.

# 

# \### Features of the Output Files:

# \* \*\*Detailed Naming System:\*\* The final output filenames are dynamically generated and include in-depth details of the structure.

# \* \*\*Angstrom Dimensions:\*\* For structures like \*Tri-Alloy Shell, Core-Alloy Shell, Bishell, and Bi-Alloy Shell\*, the specific physical dimensions are recorded in \*\*Angstroms ($\\mathring{A}$)\*\* directly within the filename.

# \* \*\*Geometry Visualization:\*\* For every single simulated wavelength, a dedicated file is generated so you can inspect and verify the simulated physical geometry.



