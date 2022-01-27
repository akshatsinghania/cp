def change(spaces, r1):
  start = r1[0]/r1[1]
  for i in range(len(spaces)):
    if(spaces[i] - start) < 1:
      return [-1, -1]
    start = spaces[i] - start
  return r1

def solution(lst):
  spaces = [lst[i+1] - lst[i] for i in range(len(lst) - 1)]
  f_space = sum(spaces[::2]) - sum(spaces[1::2])

  # print(f_space)
  if(f_space <= 2):
    return [-1,-1]

  r1 = 0
  if(len(spaces)%2 == 0):
    r1 = [2*f_space, 1]
  else:
    if(f_space%3 == 0):
      r1 = [2*f_space/3, 1]
    else:
      r1 = [2*f_space, 3]

  return change(spaces, r1)