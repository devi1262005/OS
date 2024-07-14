#!/bin/bash
echo "Enter a sentence:"
read sentence
word_count=$(echo $sentence | wc -w)
echo "Number of words: $word_count"
