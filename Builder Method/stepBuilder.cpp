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

class MethodStep;
class HeaderStep;
class OptionalStep;

class UrlStep {
    public:
        virtual MethodStep& withUrl(const string& url) = 0;
};

class MethodStep {
    public:
        virtual HeaderStep& withMethod(string method) = 0;
};

class HeaderStep {
    public:
        virtual OptionalStep& withHeader(const string& key , const string& value) = 0;
};

class OptionalStep {
    public:
        virtual ~OptionalStep() {}
        virtual OptionalStep& withBody(const string& body) = 0;
        virtual OptionalStep& withTimeout(int time) = 0;
        virtual HttpReqest build() = 0;

};

class HttpReqestBuilder :
    public UrlStep,
    public MethodStep,
    public HeaderStep,
    public OptionalStep {

    private:
        HttpReqest req;
    
    public:
        MethodStep& withUrl(const string& u)
        {
            req.url = u;
            return *this;
        }

        HeaderStep& withMethod(string method)
        {
            req.method = method;
            return *this;
        }

        OptionalStep& withHeader(const string& key , const string& value)
        {
            req.headers[key] = value;
            return *this;
        }

        OptionalStep& withBody(const string& body)
        {
            req.body = body;
            return *this;
        }

        OptionalStep& withTimeout(int time)
        {
            req.timeout = time;
            return *this;
        }

        HttpReqest build() {
            if(req.url.empty()) 
                throw runtime_error("URL cannot be empty");
            return req;
        }

        static UrlStep& getBuilder (){
            return *(new HttpReqestBuilder());
        }
};

int main()
{
    HttpReqest request = HttpReqestBuilder::getBuilder()
    .withUrl("https://example.com")
    .withMethod("POST")
    .withHeader("content-type" , "application/json")
    .withBody("{\"name\" : \"Aditya\"}")
    .withTimeout(60)
    .build();

    request.execute();
}