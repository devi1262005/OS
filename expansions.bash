#!/bin/bash
echo "Enter a filename:"
read filename
echo "File extension: ${filename##*.}"
