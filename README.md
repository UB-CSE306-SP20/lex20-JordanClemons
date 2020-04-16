# LEX20

This lab exercise builds off the code in an earlier lab exercise. The bugs engineered into the code for that exercise have been removed.

In this exercise you will experiment with the code to restructure it in various ways to better understand the impact this has on the efficiency of the code and the quality of the performance informationreported by the tools.

You will now run through steps, each containing several tasks.  Put answers to questions into the [LEX20 response form](https://docs.google.com/forms/d/e/1FAIpQLSeqRbIifFbk-mzOyiR6ey1KschvQ-penIKw3CCyjO-hnju5dg/viewform?usp=sf_link).

## Step 1
Make a subdirectory named `step1`, and move the output files created along the way into this subdirectory.  Before proceeding to step 2 be sure to add/commit/push these files to the remote repo on GitHub.

### gprof and gcov
Run `make andRunPerformance`.  Copy the output files produced by gprof and gcov into lthe `step1` subdirectory, *before proceeding on to run callgrind*.  This is important, as `make andRunCallGrind` invokes `make clean` and will remove these output files.  If you accidentally remove them you will need to re-create them.

Answer the questions [gprof 1] and [cgov 1] in the response form.

### callgrind
Run `make andRunCallGrind`.  Run callgrind_annotate to produce output files as indicated in the the questions [callgrind 1a] and [callgrind 1b] in the response form.  Answer these questions, and then copy the output files produced by callgrind_annotate into lthe `step1` subdirectory.

### hotspots
Answer [hotspots 1] in the response form.

## Step 2
Make a subdirectory named `step2`, and move the output files created along the way into this subdirectory.  Before proceeding to step 3 be sure to add/commit/push these files to the remote repo on GitHub.

Refactor the code so that the hotspots are isolated in separate functions. To help with this step, first open the counts.c file. (To refactor code is to change the design of the code in a way that preserves functionality.)

Find the code that is delimited by the two lines `// >>>> TASK STEP 11.1` and `// <<<< TASK STEP 11.1`. Refactor so that the code between these lines is put into its own function and replaced by the function call `shiftBuffer(buffer, size-1);`

Find the code that is delimited by the two lines `// >>>> TASK STEP 11.2` and `// <<<< TASK STEP 11.2`. Refactor so that the code between these lines is put into its own function and replaced by the function call and assignment `ch = lowerCase(ch);`

Run `make andRunTests`.  All the tests should pass. If they do not you probably did not get the refactoring correct. Fix the problem before continuing.

### gprof and gcov
Run `make andRunPerformance`.  Copy the output files produced by gprof and gcov into lthe `step2` subdirectory, *before proceeding on to run callgrind*. Answer the questions [gprof 2] and [cgov 2] in the response form.

### callgrind
Run `make andRunCallGrind`.  Run callgrind_annotate to produce output files as indicated in the the questions [callgrind 2a] and [callgrind 2b] in the response form.  Answer these questions, and then copy the output files produced by callgrind_annotate into lthe `step2` subdirectory.

### hotspots
Answer [hotspots 2] in the response form.

### refactoring
Answer [refectoring 2] in the response form.

## Step 3
Make a subdirectory named `step3`, and move the output files created along the way into this subdirectory.  Before proceeding to step 4 be sure to add/commit/push these files to the remote repo on GitHub.

Modify the shiftBuffer function so that rather than just shift the buffer one position and then return, it repeatedly shifts the buffer one position until a space is shifted into position 0, or until the entire buffer has been shifted (i.e. there was no space in buffer past position 0 to start with).  If there was no space, then the buffer should be cleared in the same way that happens when a match is found.

Run `make andRunTests`.  All the tests should pass. If they do not you probably did not get the code changes correct. Fix the problem before continuing.

### gprof and gcov
Run `make andRunPerformance`.  Copy the output files produced by gprof and gcov into lthe `step3` subdirectory, *before proceeding on to run callgrind*. Answer the questions [gprof 3] and [cgov 3] in the response form.

### callgrind
Run `make andRunCallGrind`.  Run callgrind_annotate to produce output files as indicated in the the questions [callgrind 3a] and [callgrind 3b] in the response form.  Answer these questions, and then copy the output files produced by callgrind_annotate into lthe `step3` subdirectory.

### hotspots
Answer [hotspots 3] in the response form.

### impact
Answer [impact 3] in the response form.

## Step 4
Make a subdirectory named `step4`, and move the output files created along the way into this subdirectory.  Before proceeding to step 5 be sure to add/commit/push these files to the remote repo on GitHub.

Modify the shiftBuffer function so that rather always shifting by one, the shift is done in one shot. Do this by finding the offset to the next space in the buffer, or if there isn't one, to the end of the buffer (or call clearBuffer).

Run `make andRunTests`.  All the tests should pass. If they do not you probably did not get the code changes correct. Fix the problem before continuing.

### gprof and gcov
Run `make andRunPerformance`.  Copy the output files produced by gprof and gcov into lthe `step4` subdirectory, *before proceeding on to run callgrind*. Answer the questions [gprof 4] and [cgov 4] in the response form.

### callgrind
Run `make andRunCallGrind`.  Run callgrind_annotate to produce output files as indicated in the the questions [callgrind 4a] and [callgrind 4b] in the response form.  Answer these questions, and then copy the output files produced by callgrind_annotate into lthe `step4` subdirectory.

### hotspots
Answer [hotspots 4] in the response form.

### impact
Answer [impact 4] in the response form.

## Step 5
Answer the three reflection questions, [Reflection 5a], [Reflection 5b], and [Reflection 5c], in the response form.

# Wrapping up
Ensure that you have added, committed, and pushed your files to the remote repo on GitHub.

Also give your feedback on the [LEX 20 Feedback Form](https://docs.google.com/forms/d/e/1FAIpQLSdQetaeVu1UopP3YsTk0dBFkU-Llb_fLLXSfE44eMluGw84Rw/viewform?usp=sf_link).
