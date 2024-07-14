#!/bin/bash
echo "Enter string to search:"
read search_string
echo "Enter filename to search in:"
read filename
grep $search_string $filename
