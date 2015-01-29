class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        out=[]
        record={}
        for x in strs:
            temp="".join(sorted(x))
            if temp not in record:
                record[temp]=x
            else:
                if record[temp]!=None:
                    out.append(record[temp])
                    record[temp]=None
                out.append(x)
        return out