import csv
import sys

if len(sys.argv) != 3:
    print("Usage: python data.csv sequence.txt")
    sys.exit(1)

dna = open(sys.argv[2], "r").read()

with open(sys.argv[1]) as csvfile:
    reader = csv.DictReader(csvfile)
    str_tested = reader.fieldnames[1:]
    strs_count = {}

    for STR in str_tested:
        index = 0
        longest_sequence = 0
        current_sequence = 0

        while index < len(dna):
            current_str = dna[index:index + len(STR)]

            if current_str == STR:
                current_sequence += 1
                index += len(STR)
            else:
                if current_sequence > longest_sequence:
                    longest_sequence = current_sequence
                current_sequence = 0
                index += 1
        
        strs_count[STR] = longest_sequence

    for person in reader:
        name = person["name"]
        is_found = True

        for STR in str_tested:
            if int(person[STR]) != strs_count[STR]:
                is_found = False
                break
        
        if is_found:
            print(name)
            sys.exit(0)

    print("No Match!")