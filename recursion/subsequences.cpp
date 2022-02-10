// Question Link : https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087

void solve(string str, string output, int index, vector<string> &ans)
{
    // base case
    if(index >= str.size())
    {
        if(output.size() > 0)
        	ans.push_back(output);
        return;
    }
    
    // exclude
    solve(str, output, index+1, ans);
    
    // include
    output.push_back(str[index]);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str){
	vector<string> ans;
    string output;
    solve(str, output, 0, ans);
    return ans;
}