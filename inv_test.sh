#!/bin/zsh

# Force the script to expand and allow aliases
setopt aliases

if [ -f "$HOME/.zshrc" ]; then
	source "$HOME/.zshrc"
fi

solve()
{
	echo "Solving: $1"
	bin/build "$1" $2
}

dotc build
solve "1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4"
solve "2122342121232321"
solve "2 1 2 2 3 4 2 1 2 1 2 3 2 3 2 4"

