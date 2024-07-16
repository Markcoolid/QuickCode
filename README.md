So over the weekend 5/4-5/5 2024 I decided to write a programming language. I didn't set out to write the next C or Python, but I liked the idea of a very simplistic language that writes similarly to Python and compiles and runs like C++. I don't know what goes into compiling a program to assembly, and I didn't when I started, so I decided to work on a transpiled language,  where I write a compiler that compiles my language into another high-level language before compiling it down to machine code. I decided to code my compiler in C++, as well as use C++ as the intermediary language. 

I started with a simple print function. 
I wanted to user to be able to quickly understand the language, so I decided to keep the syntax simple.  

Where C-based languages use cout << "Text Here"; To print text from a standard library, I took inspiration from Python and made the syntax in my language  
Print "Text Here"  

The next thing I implemented was variables because they are the basis for everything a language can do. I ended up having str for a string and int for an int.
But there was a problem that wasn't as easily solvable as I thought it was going to be.Since str and int were defining the vars, I made it so an input line that could edit the contents of a string.
For editing the contents of a variable in the code there was an underlying issue of how I was praising the file for its contents. I was looking for the syntax on each line and then taking the 
data to convert it into an auto-generated C++ program. By looking for int 
and str and then defining them, I couldn't modify them with int and str.
But I didn't know the var names to let the compiler know how to deal with 
those vars specifically. I settled on the temporary solution of making 
strdef define a string and intdef define an int. This freed up int and str to 
modify the vars.   

I mentioned input above, but once vars with inputs were made, which was 
simply a direct conversion to C++-like print, it raised an issue in print. 
How to print a var. The way the print scanning works is it looks for the 
first set of quotes, then the second, and takes just what between those to 
print. Most languages print vars by not having quotes, but this would raise 
more issues in the system I had just spent hours debugging and require a 
complete rewrite of any code involving variables. So similar to how I 
solved the problem with changing vars in code, I made it so you can print 
vars by using addition signs around the var name in print.   

So far I had printing, input, and vars. You could write a very simplistic 
program that takes in a name and says hello to them like this.   

print "What's your name?\n" 
strdef usersname = "startingvalue" 
input +usersname+ 
print "Hello there " 
print +usersname+ 

This still isn't a very good programming language, what IF we wanted to 
compare 2 vars, or check a var to see if a string matches?  

I created the if and while operators at about the same time, they allow for 
if-then statements to work similarly to how they do in a language like 
C++. 
By using the same logic as before I could take in an argument for an if or 
while statement enclosed in dollar signs.   

Finally, I made an end function that declared where the end of an if or 
while statement is.

This was about 7 hours of work and I'm happy with the result. I added 
one last function called debug, which allows the compiler to give you the 
code from the intermediary language, in this case, it's C++, as well as the 
executable file. I'll publish it here when I work out some of the smaller 
bugs and after I make improvements to what files it just refuses to read.


I don't believe anyone should use this in it's state, but I learned a lot from making it.
I had only edited files with code in python before now, and hadn't done more complicated logic when working with those. 

If you do wish to modify this and use it. You need to have g++ installed to compile .qc files into executables.

I might continue work sometime in the future, but for now there are no guarntees as I want to make more intresting projects, and I'm sure there's a better way to write this.

Thanks for supporting my projects by reading this.




Syntax


print:

Print "text"
Print +varName+


strdef:

strdef stringName = "stringValue"


str:

str stringName = "stringValue"


intdef:

intdef intName = intValue


int:

int intName = intValue


input:

input +stringName+


if:

if $condition$ 
examples: 1==1  string == "stringvalue"  int > 5
must always be ended with a end
example:
if$condition$
print "condition is met"
end


while:

while $condition$ 
examples: 1==1  string == "stringvalue"  int > 5
must always be ended with a end
example:
while $condition$
print "condition is met"
end




inputint:
BROKEN
inputint +intName+


math:
math intName = intName + 1


debug:
doesn't dispose of output.cpp for debugging purposes.


clear:
clears the console


exit:
exits out of a while loop early


