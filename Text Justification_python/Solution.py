class Solution:
    # @param words, a list of strings
    # @param L, an integer
    # @return a list of strings
    def fullJustify(self, words, L):
        Out=[]
        index=0
        while index<len(words):
            left=L-len(words[index])
            i=0
            Sum=len(words[index])
            for i in range(index+1,len(words)):
                if len(words[i])+1<=left:
                    left-=len(words[i])+1
                    Sum+=len(words[i])
                else:
                    break
            else:
                tempString=" ".join(words[index:])
                while len(tempString)<L:
                    tempString+=" "
                Out.append(tempString)
                break
            tempString=words[index]
            if i==index+1:
                while len(tempString)<L:
                    tempString+=" "
                Out.append(tempString)
                index=i
                continue
            nSpace=(L-Sum)//(i-1-index)+1
            n=(L-Sum)%(i-1-index)
            Space=" "*nSpace
            for k in range(index+1,index+n+1):
                tempString+=Space
                tempString+=words[k]
            Space=" "*(nSpace-1)
            for k in range(index+n+1,i):
                tempString+=Space
                tempString+=words[k]
            Out.append(tempString)
            index=i
                
        return Out

print Solution().fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16)