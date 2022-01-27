def solution(s):
    letters = "abcdefghijklmnopqrstuvwxyz"
    letters_map = {}
    for x in range(len(letters)):
        letters_map[letters[x]] = letters[len(letters)-x-1]
    ans=""
    for letter in s:
        if letter in letters_map:
            ans+=letters_map[letter]
        else:
        	ans+=letter
    return ans


