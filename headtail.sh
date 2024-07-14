#!/bin/bash
echo "Enter filename to display head:"
read filename
echo "Head of file $filename:"
head $filename

echo "Enter filename to display tail:"
read filename
echo "Tail of file $filename:"
tail $filename
