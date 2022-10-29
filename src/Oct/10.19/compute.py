from copy import deepcopy
class Solution:
    depth = 0
    res = []
    
    def isValidNum(self, num):
        if(num < 2**31-1 and -2**31):
            return True
        return False
    def get_1024(self, nums, operators):
        self.depth+=1
        if(self.depth > 3):
            return False
        if(self.depth == 1):
            for i in range(len(nums)):
                for j in range(i+1, len(nums)):
                    for operator in operators:
                        try:
                            new_num = eval(str(nums[i]) + str(operator) + str(nums[j]))
                        except:
                            continue
                        if(not self.isValidNum(new_num)):
                            continue
                        nums_new = deepcopy(nums)
                        nums_new.remove(nums[i])
                        nums_new.remove(nums[j])
                        nums_new.insert(0, new_num)
                        operators_new = deepcopy(operators)
                        operators_new.remove(operator)
                        sub_res = self.get_1024(nums_new, operators_new)
                        self.depth-=1
                        if(sub_res):
                            self.res+=[nums[i], operator, nums[j]]
                            return True
                        try:
                            new_num = eval(str(nums[j]) + str(operator) + str(nums[i]))
                        except:
                            continue
                        if(self.depth == 3 and new_num==1024):
                            self.res+=[nums[j], operator, nums[i]]
                            return True
                        nums_new = deepcopy(nums)
                        nums_new.remove(nums[i])
                        nums_new.remove(nums[j])
                        nums_new.insert(0, new_num)
                        operators_new = deepcopy(operators)
                        operators_new.remove(operator)
                        sub_res = self.get_1024(nums_new, operators_new)
                        self.depth-=1
                        if(sub_res):
                            self.res+=[nums[j], operator, nums[i]]
                            return sub_res
        else:
            for j in range(1, len(nums)):
                for operator in operators:
                    try:
                        new_num = eval(str(nums[0]) + str(operator) + str(nums[j]))
                    except:
                        continue
                    if(not self.isValidNum(new_num)):
                            continue
                    if(self.depth == 3 and new_num==1024):
                        self.res+=[nums[0], operator, nums[j]]
                        return True
                    nums_new = deepcopy(nums)
                    nums_new.remove(nums[0])
                    nums_new.remove(nums[j])
                    nums_new.insert(0, new_num)
                    operators_new = deepcopy(operators)
                    operators_new.remove(operator)
                    sub_res = self.get_1024(nums_new, operators_new)
                    self.depth-=1
                    if(sub_res):
                        self.res+=[nums[0], operator, nums[j]]
                        return sub_res
        return False

# nums = ["1337", "29", "4", "2", "32", "26", "23"]
# operators = ["<<", "|", "^", ">>"]

nums = ["0","3","1337"]
operators = ["*", "<<"]
solution = Solution()
solution.get_1024(nums, operators)
print(solution.res)
