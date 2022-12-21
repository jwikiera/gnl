# gnl

My implementation of the get next line project (including bonus). The assignement PDF can be found at the root of the repo (gnl_subject.pdf).

## Description of the project:
It is essentially a function that reads the content of a text file line by line, given a file descriptor. Each call gets a new line, as a NULL terminated string. Any file descriptor can be passed, as long as a file is not closed and repoened, the function will remember its progress in a given file. The files are read by chunks of size specified with a compilation flag (`-D BUFFER_SIZE=42`). The core code is inside of the `zeGnl` folder, the Makefile and test files are included for convenience and testing. No more work will be done to clean up this repo, as the function will be incorporated in my `libft` library.
