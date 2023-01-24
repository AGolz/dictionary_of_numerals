# dictionary_of_numerals

A program that takes a number from a command-line argument and convert it to a symbolic language.

**Executable file name:** numbers_dict

**The source code is compiled as follows:**

```
$>make
Making Numbers_dict2...
numbers_dict
```
The makefile also contains the rules `clean` - delete object files, `fclean` - delete everything executable file, including , and `re` - delete everything, including executable file and compile again.

The program can receive up to 2 command line arguments：

- If the number of command line arguments is one `./numbers_dict 178920000`, then the argument is a converted number.

<p align="center">
<img width="525" alt="Screen Shot 2023-01-24 at 8 08 54 PM" src="https://user-images.githubusercontent.com/51645091/214346455-389d75b2-45be-49d5-b27d-df21f035217b.png">
</p>

- If there are 2 command line arguments `./numbers_dict numbers.dict 178920000`, the 1st argument is the name of the new dictionary, the 2nd argument is the value that needs to be converted.

<p align="center">
<img width="640" alt="Screen Shot 2023-01-24 at 8 15 30 PM" src="https://user-images.githubusercontent.com/51645091/214347719-007b4739-8e47-4bc1-9525-dc1fa56976bc.png">
</p>

The program uses a dictionary (numbers.dict) as a project resource.

You can connect any other dictionaries written using the numbers.edit template:

```
[a number][0 to n spaces]:[0 to n spaces][any printable characters]\n
```

for example:
```
18: dix-huit\n
```

**each line in the dictionary must necessarily end with `\n`**

This project was created during the [school 42](https://www.42.fr) training program and helps to delve into the problem of storing numeric values exceeding the size of the maximum `int` and transmitted to the program by a `char` type string.

The program processes numbers up to 99999999999999999999999999999999999 inclusive.

<img width="1336" alt="Screen Shot 2023-01-24 at 8 03 32 PM" src="https://user-images.githubusercontent.com/51645091/214344882-1862a3da-2ceb-47c7-8e75-10d36b4687c8.png">

Need help: emaksimo@student.42yerevan.am

