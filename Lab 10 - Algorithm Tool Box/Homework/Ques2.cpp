bool isGood(int n, string s, int l, int r)
{
    //Return true if good, false if not
    if (l > 0)
    {
        for (int i = 0; i < l; i++)
        {
            if (s[i] == s[l]) return true;
        }
    }
    if (r < int(s.size()) - 1)
    {
        for (int i = r + 1; i < (int)s.size(); i++)
        {
            if (s[i] == s[r]) return true;
        }
    }

    return false;
}