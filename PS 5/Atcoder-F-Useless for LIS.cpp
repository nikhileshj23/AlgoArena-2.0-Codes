/*
Not able to implement but here is my idea.
start with the element at 1st position. We will start making a tree. A new branch will start only if the element 
being joined is greater than it's parent vertex. In that way, all the branches of the tree will represent increasing subsequences.
Then, we just have to go over the branches of max length and store indices of the elements we have found along the way.
*/