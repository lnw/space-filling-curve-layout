# Experimental 2D space filling curve layouts for std::mdspan

So far there are 2 space filling curves implemented: Hilbert (with blocks of
256x256) and Morton (with blocks of 256x256 or 16kx16k).  For either of them
the layout places squares in row major order; an image type making use of them
sacrifices memory for speed if the requested image size is not a multiple of
the block size.  Larger blocks may offer better cache line utilization (with
quickly diminishing returns) at the expense of more wasted memory and more
expensive index computations.


