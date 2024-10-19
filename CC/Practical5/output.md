(base) MOHIT@MacBook-Air Practicals % python3 -u "/Users/MOHIT/Documents/GitHub/Practicals/CC/Practical5/ll1.py"</br>

Stack                         Input          Action</br>
------------------------------------------------------------</br>
$                             aabb$          Apply rule: S → A B
$ B                           aabb$          Apply rule: A → a A
$ B A                         aabb$          Matched a
$ B                           abb$           Apply rule: A → a A
$ B A                         abb$           Matched a
$ B                           bb$            Apply rule: A → ε
$                             bb$            Apply rule: B → b B
$ B                           bb$            Matched b
$                             b$             Apply rule: B → b B
$ B                           b$             Matched b
$                             $              Apply rule: B → ε
                              $              Matched $
Input successfully parsed.
(base) MOHIT@MacBook-Air Practicals % 