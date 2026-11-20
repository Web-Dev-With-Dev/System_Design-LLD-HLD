#include <bits/stdc++.h>
using namespace std;

class HttpReqest {
    private:
        string url;
        string method;
        map<string,string> headers;
        map<string,string> queryParams;
        string body;
        int timeout;

        HttpReqest() {  }

    public:

        friend class HttpReqestBuilder;

        void execute()
        {
            cout << "Executing " << method << " request to " << url << endl;
            
            if(!queryParams.empty())
            {
                cout<<"Query Parameters: " << endl;
                for(const auto& param : queryParams)
                    cout<< " " << param.first << "=" << param.second << endl;
            }

            cout <<" headers : "<<endl;
            for(const auto& header : headers)
                cout<<" " << header.first << " : " << header.second << endl;

            if(!body.empty())
                cout<<"Body : " << body << endl;

            cout << "Timeout : " << timeout <<endl;
            cout << "Rquest executed successfully !!!" << endl;
        }
};

class HttpReqestBuilder{
    private:
        HttpReqest req;
    
    public:
        HttpReqestBuilder& withUrl(const string& u)
        {
            req.url = u;
            return *this;
        }

        HttpReqestBuilder& withMethod(string method)
        {
            req.method = method;
            return *this;
        }

        HttpReqestBuilder& withHeader(const string& key , const string& value)
        {
            req.headers[key] = value;
            return *this;
        }

        HttpReqestBuilder& withQueryParams(const string& key , const string& value)
        {
            req.queryParams[key] = value;
            return *this;
        }

        HttpReqestBuilder& withBody(const string& body)
        {
            req.body = body;
            return *this;
        }

        HttpReqestBuilder& withTimeout(int time)
        {
            req.timeout = time;
            return *this;
        }

        HttpReqest build() {
            if(req.url.empty()) 
                throw runtime_error("URL cannot be empty");
            return req;
        }
};

int main()
{
    HttpReqest request = HttpReqestBuilder()
    .withUrl("https://example.com")
    .withMethod("POST")
    .withHeader("content-type" , "application/json")
    .withHeader("Accept" , "application/json")
    .withQueryParams("key" , "12345")
    .withBody("{\"name\" : \"Aditya\"}")
    .withTimeout(60)
    .build();


    request.execute();
}