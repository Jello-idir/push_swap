This project has been created as part of the 42 curriculum by *aait-idi*

<h2 style="
color: #FFFFFF;
font-size: 24px;
font-weight: 800">
Description
</h2>
	<img
	src="https://raw.githubusercontent.com/Jello-idir/push_swap/refs/heads/master/src/push_swap.png"
	width="auto"
	/>

push_swap is about sorting a set of non-duplicate integers in a **STACK-A** using another empty **STACK-B** as few operations as possible using the given limited instructions, it's Goal is to learn **FIFO** aka stack, **Alrorithms**, **Sorting** and **Optimization**.
the program takes integers as arguments and returns the intructions needed to sort them.

we only have these instructions in hand:

**`Push()`**
- pushes the top element of a stack to the other stack.
- pa to push to **STACK-A**, pb to push to **STACK-B**.

	<img
	src="https://raw.githubusercontent.com/Jello-idir/push_swap/refs/heads/master/src/_push.gif"
	width="800"
	/>
___


**`Swap()`**
- swaps the top 2 elements of a stack.
- sa to swab **STACK-A**, sb to swap **STACK-B**.
- ss for both sa and sb.

	<img
	src="https://raw.githubusercontent.com/Jello-idir/push_swap/refs/heads/master/src/_swap.gif"
	width="800"
	/>
___

**`Rotate()`**
- shifts all elements in a stack up, and the first element goes to bottom
- ra to rotate **STACK-A**, rb to rotate **STACK-B**.
- rr for both, ra and rb.

	<img
	src="https://raw.githubusercontent.com/Jello-idir/push_swap/refs/heads/master/src/_rotate.gif"
	width="800"
	/>
___

**`Reverse Rotate()`**
- shifts all elements in a stack down, and the last element goes to top.
- rra to reverse rotate **STACK-A**, rrb to reverse rotate **STACK-B**.
- rrr for both, rra and rrb.

	<img
	src="https://raw.githubusercontent.com/Jello-idir/push_swap/refs/heads/master/src/_reverse_rotate.gif"
	width="800"
	/>
___

<h2 style="
color: #FFFFFF;
font-size: 24px;
font-weight: 800">
Instructions
</h2>

	how does my push_swap sort?

My sorting algorithm is iterative and it has 2 Major steps `Threshholding`, `Greedy`, thats all i do to sort any `set of numbers > 3`.

*my algo does the following:*

**`| Threshhold:`**
- choose a ratio for example `ratio = 1.42`.
- anything smaller than `stack_size / ratio` is marked as beying threshhold, and will be pushed to the stack b.
- the remaining in stack A, will have the same process again, until stack A is empty.

*this way i garentee ill have the small number more towards the top, and bigger number towards the bottom.*

**`| Greedy:`**
- get the biggest elemtn in stack B to the top, and push it to stack A.
- loop over each element in stack B and figure out the closest one to be pushed to stack B.
- get the closest to TOP as well as it's detination in stack A and then push it to A.

*we are not done yet!*

**`| Iteration:`**
- store this specific ratio in a variable along with the number of instruction I did to sort the stack.
- Increment the ratio by 0.03 and try the sort all over again, until it's `> 3`.
- at the end, the ratio with the minumum number of instructions gets executed one more time.
- display the moves.

*are you wondering...*

	how did I figure out the ratio range?

<h2 style="
color: #FFFFFF;
font-size: 24px;
font-weight: 800">
Automation
</h2>

- This target allows me to automate testing my push_swap with random number.

	<img
	src="https://raw.githubusercontent.com/Jello-idir/push_swap/refs/heads/master/src/makefile_stress.png"
	width="700"
	/>

- This target allows me to automate testing my push_swap with random number.
- and I try wider range of ratios and log the best in a file.

	<img
	src="https://raw.githubusercontent.com/Jello-idir/push_swap/refs/heads/master/src/ratio_log_500.png"
	width="400"
	/>
- Then I calculated the minimum and maximum which is `1.3 to 3`

<h2 style="
color: #FFFFFF;
font-size: 24px;
font-weight: 800">
Resources
</h2>

| link                                                                         | used for                                                    |
| ---------------------------------------------------------------------------- | ----------------------------------------------------------- |
| [Github copilot](https://virtualbox.org/)                                 | was used for making a python script to test the project        |
