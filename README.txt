This program removes vocals from stereo PCM sounds stored in the canonical wav format.

Here's how the algorithm works.
Copy the first 44 bytes from the input file to the output file without changing those bytes. Those 44 bytes contain important header information that should not be modified by the program.
Next, treat the rest of the input file as a sequence of shorts. Take each pair of shorts left and right, and compute combined = (left - right) / 2. Write two copies of combined to the output file.

Why does it work?

For the curious, a brief explanation of the vocal-removal algorithm is in order. As you noticed from the algorithm, we are simply subtracting one channel from the other (and then dividing by 2 to keep the volume from getting too loud). So why does subtracting the left channel from the right channel magically remove vocals?

When music is recorded, it is sometimes the case that vocals are recorded by a single microphone, and that single vocal track is used for the vocals in both channels. The other instruments in the song are recorded by multiple microphones, so that they sound different in both channels. Subtracting one channel from the other takes away everything that is ``in common'' between those two channels which, if we're lucky, means removing the vocals.