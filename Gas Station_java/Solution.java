public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) 
    {
        if(gas.length==0||cost.length==0||gas.length!=cost.length)
        	return -1;
        int begin=0,sum=0,total=0;
        int size=gas.length;
        for(int i=0;i<size;++i)
        {
        	total+=gas[i]-cost[i];
        	if(sum<0)
        	{
        		begin=i;
        		sum=gas[i]-cost[i];
        	}
        	else
        	{
        		sum+=gas[i]-cost[i];
        	}
        }
        if(total>=0)
        	return begin;
        else
        	return -1;
    }
}