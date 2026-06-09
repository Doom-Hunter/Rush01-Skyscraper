#!/bin/zsh

# Force the script to expand and allow aliases
setopt aliases

if [ -f "$HOME/.zshrc" ]; then
	source "$HOME/.zshrc"
fi

solve()
{
	echo "=========================================================================================="
	if [ -n "$2" ]; then
		echo "  Solving $2x$2: $1"
	else
		echo "  Solving: $1"
	fi
	echo "------------------------------------------------------------------------------------------"
	bin/build "$1" $2
}

dotc build
# solve "2 1 2 2 3 4 2 1 2 1 2 3 2 3 2 1"
# solve "1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1"
# solve "1 2 3 4 2 2 2 1 1 2 2 2 4 3 2 1"
# solve "1 3 4 3 3 2 3 1 2 3 3 5 1 3 3 3 2 2 2 1 2 3 3 5" 6
# solve "2 2 3 2 4 4 1 2 5 1 4 3 2 4 2 3 2 3 3 1 2 1 2 5 2 2 3 3" 7
# solve "2 3 3 3 1 4 5 2 3 3 2 1 5 4 2 3 2 4 2 1 3 4 2 4 4 1 5 3 2 2 2 3" 8
# bin/build "5 4 3 2 1 1 2 3 4 5 5 4 3 2 1 1 2 3 4 5" 5
echo "Testing Generated Boards"
solve "$(tools/gen 4)" 4
solve "$(tools/gen 5)" 5
solve "$(tools/gen 6)" 6
solve "$(tools/gen 7)" 7
solve "$(tools/gen 8)" 8
# solve "$(tools/gen 9)" 9
