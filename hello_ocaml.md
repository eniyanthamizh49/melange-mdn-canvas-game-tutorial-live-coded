
# OCaml Code Documentation

This document provides an overview and explanation of the OCaml code.



## Code Overview

### Printing Strings

```ocaml
print_endline "thamizh"
```

This line prints the string "thamizh" followed by a newline.

### Arithmetic Operation

```ocaml
let tint = 10.5 /. 2.5;;
Printf.printf "%f\n" tint;;
```

This code performs a floating-point division and prints the result.

### Boolean Conjunction and Disjunction

```ocaml
let conjunBool = true && false;;
Printf.printf "%b\n" conjunBool;;

let disconjunBool = true || false;;
Printf.printf "%b\n" disconjunBool;;
```

Here, boolean operations (`&&`, `||`) are performed, and the results are printed.

### String Concatenation

```ocaml
let constring = "thamizh" ^ "eniyan";;
print_endline constring
```

This section concatenates two strings and prints the result.

### Lists 

```ocaml
let numbers = [10; 20; 30]
let () = List.iter (Printf.printf "%d ") numbers
```

### Tuple
```ocaml 
let a_tuple = (3, "three");;

let (x, y) = a_tuple in
Printf.printf "The tuple is (%d, \"%s\")\n" x y;;
```

### Variants

```ocaml
type day = Sun | Mon | Tue | Wed | Thu | Fri | Sat

let int_of_day d =
  match d with
  | Sun -> 1
  | Mon -> 2
  | Tue -> 3
  | Wed -> 4
  | Thu -> 5
  | Fri -> 6
  | Sat -> 7
;;
print_int(int_of_day Wed)
```

This part defines a variant type `day` and a function that converts a day into its corresponding integer value.

### Custom Record Type
```ocaml
(* Define a custom datatype 'person' *)
type person = {
  name : string;
  age : int;
  occupation : string;
}

(* Function to print a person's details *)
let print_person p =
  Printf.printf "Name: %s\n" p.name;
  Printf.printf "Age: %d\n" p.age;
  Printf.printf "Occupation: %s\n" p.occupation

(* Create an instance of 'person' *)
let thamizh = { name = "Thamizh"; age = 21; occupation = "Software Developer" }

(* Call the function to print the details *)
let () = print_person thamizh
```
### compile cmd
ocamlc -o outputname filename.ml
./outputname