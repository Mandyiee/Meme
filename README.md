# MEME

## Overview

This C program is designed to automate the process of generating video clips from images using `ffmpeg`. The program reads all the images from the folder AND processes each image with an `ffmpeg` command to combine it with an audio file, and generates a new video.


### Usage

1. **Directory Setup**: 
   - Ensure you have the following directories set up:
     - `/images`: This is where your input images should be stored.
     - `/used/images`: Processed images will be moved here.
     - `/new`: This folder will be cleared of files at the start of the program.
     - `audio/laff.mp3`: The audio file that will be combined with each image.
   
2. **Running the Program**:
   - Compile the program:
     ```bash
     make
     ```
   - Run the program:
     ```bash
     ./create
     ```


### Conclusion

This program automates the generation of video clips from images with audio overlay and organizes the files efficiently. While it functions as intended, several enhancements could be made to improve performance, flexibility, and robustness.
