// 2798. Number of Employees Who Met the Target
// Logic: Iterate through the 'hours' array using a for-loop. 
// For each employee, check if their hours are >= the target. 
// If they are, increment the count. Return the final count.

int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target) {
    int count = 0;
    for (int i = 0 ; i < hoursSize ; i++){
        if (hours[i] >= target){
            count++;
            
        }
    }
return count;
}