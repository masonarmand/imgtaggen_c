# imgtaggen_c
Simple program to generate a long list of html <img> tags (rewritten in C).  
Works pretty much the same as [the original](https://github.com/masonarmand/imgtaggen) python version.

## What is this used for?
If you want to have a page containing hundreds of images but don't want to write each &lt;img&gt;
tag by hand, you can use this simple script to do this for you.

## Why did you rewrite it in C?
I am bored!

## Usage
```
imgtaggen <directory>
```
Output can be appended to file:
```
imgtaggen ~/Pictures >> out.txt
```

## Installation
```
git clone https://github.com/masonarmand/imgtaggen_c.git
cd imgtaggen_c
sudo make install
```
