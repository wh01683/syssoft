Virtual Memory Paging Project
===========

Repository for System Software Fall 2014 semester project; group 1.

Project Members:

Trent Holliday  <wh01818@georgiasouthern.edu> 

Robert Howerton <wh01683@georgiasouthern.edu>

Jared Baker     <jb15064@georgiasouthern.edu>

Denzel Kent     <dk01190@georgiasouthern.edu>

## How to run
####Instructions on running (Linux):

1) Download all files and extract them into a folder

2) Run the run.sh file inside the folder containing the .cpp files with the following command:

 `./run.sh`
	
  Optional arguments:
  
  * `./run.sh String int`, where string is alphabet characters to use as pages and int is number of 
  slots to have in page table memory
  
  Ex.
  * `./run.sh "abceadccab"` , runs the algorithms on the string of pages specified
  * `./run.sh "abceadccab" 5` , runs the algorithms on the string of pages specified and the number of
  slots in page table memory is 5
  
  When no arguments are given a random string with a random length from 5 to 15, selecting from the first 10 alphabet letters is generated. Also the algorithms default to have a page memory size of 4 pages.

3) The test string in virtualPaging.cpp will be fed through and results from FIFO, LRU, WS, and Optimal
will be displayed in the console. These results include the total page fault tally and execution time in
milliseconds for each algorithm. The test string may be changed as desired through virtualPaging.cpp.


####Instructions on running (Windows):

1) Download all .cpp files and extract them into a folder.

2) Compile all files

3) Run "virtualPaging.cpp"

4) The test string in virtualPaging.cpp will be fed through and results from FIFO, LRU, WS, and Optimal
will be displayed in the console. These results include the total page fault tally and execution time in
milliseconds for each algorithm. The test string may be changed as desired through virtualPaging.cpp.


  
  
  
