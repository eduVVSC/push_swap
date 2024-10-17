
<h1 align="center"> Push_Swap Project</h1>
<p > The push_swap project is about sorting in descending order, the numbers that were passed as argument to the program. To do it, we are suposed to use 2 stacks and the movemments expecified in the subject sheet. </p nnm>

### Main developed areas:
<p> - Understanding of algorithms;</p>
<p> - Program predifined action based on parameters;</p>
<p> - Claculating of the cheapest action; </p>


## How to use it:
If you wanna wanna use it, you should clone the repositiory:
```bash
git clone repository
```
After it, you will enter the directory and do:
```bash
cd push_swap
make
```
Then you are going to execute it, with the number you wanna sort in front of it:
```bash
./push_swap num1 num2 num3 num4 num5...
```

## Program Development:
<p> In order to develop the program I separated my tasks:</p> 
<p> - First I was going to understand the algorithm and wirte a psedocode to it; </p>
<p> - Second, I started doing the movement functions;</p>
<p> - Third, was just get it all together and do some adjustments;</p>

### The definition of stack:
<p> This was the part where I had to learn a little bit more about the linked list, and how to properly manipulate them. Both stacks are linked lists, where each node points to next one, and the last one points to null.</p>
<p> On the struct of my stack, I always save where the number is in the stack, where is the sorted position he is going to be on the other stack and the next and previous numbers. Doing like this, it helped me to access all the data I needed to make my movements and order the stack.</p>

### The Movements:
<p> The movements functions, are supposed to execute the movement and then print the movements made in the terminal.</p>
<p> We had available to use this movement: </p>
<p> | <strong>ra</strong>(rotate a)&emsp;&emsp;&emsp;&emsp;    |    <strong>rra</strong>(reverse rotate a)&emsp; &emsp; &emsp;|    <strong>pa</strong>(push a)&emsp; &emsp; &emsp;   |   <strong>sa</strong>(switch the first and the second from a)</p>
<p> | <strong>rb</strong>(rotate b)&emsp;&emsp;&emsp;&emsp;    |    <strong>rrb</strong>(reverse rotate b)&emsp; &emsp; &emsp;|    <strong>pb</strong>(push b)&emsp; &emsp; &emsp;   |   <strong>sb</strong>(switch the first and the second from b)</p>
<p> | <strong>rr</strong>(rotate a and b) &emsp;   |    <strong>rrr</strong>(reverse rotate a and b)</p>

## The sorting algorithm and execution:
<p> The chosen algorithm(Turkish) can be divided in two main parts: </p>

### Calculating cheapest 
<p> In order to calculate the cheepest we need to know how many moves are needed to change each one of the numbers from each position on one stack to the other in the right positioning.</p>
<p> Then we save the one that will make it in the less moves and execute the needed movse to change it</p>

### Moving 
<p> Doing the movements were the trickest part for me, in order to do it right I'm saving the number position in the stack and the number of movements needed to get it out, then I compare 
  them both and with the result I know if I need rotate or to reverse rotate the stack, so it can get to the top, and push it to the other.</p>
<p> The same happens in the receiving stack, so when I push the number for this stack, it falls in to the right place.</p>


