class Solution {
    vector<string> url;
public:
    // orginial Url to shortend url via encoding
    string encode(string longUrl) {
        url.push_back(longUrl);
        return "http://tinyurl.com/" + to_string(url.size() - 1);
    }

    //shortend url to orginial url via decoding
    string decode(string shortUrl) {
        auto pos = shortUrl.find_last_of("/");
        return url[stoi(shortUrl.substr(pos + 1))];
    }
};