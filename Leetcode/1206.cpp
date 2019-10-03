var gfw_proxy = "PROXY 127.0.0.1:10809;DIRECT";
var direct = "DIRECT";

var rules = [
"*.google.com",
"*.google.com.hk",
"*.google.hk",
"*.googleapis.com",
"*.gstatic.com",
"*.google-analytics.com",
"*.googlevideo.com",
"*.googleusercontent.com",
"*.googleadservices.com",
"*.googleusercontent.com",
"*.googlesyndication.com",
"*.mobileadtrading.com",
"*.tapad.com",
"*.youtube.com",
"*.ggpht.com",
"*.ytimg.com",
"*.zaobao.com",
"*.zaobao.com.sg",
"*.chartbeat.com",
"*.wikipedia.org",
"*.wikimedia.org",
"*.*.amazonaws.com",
"*.amazonaws.com",
"*.onesignal.com",
"*.zprk.io",
"*.blismedia.com",
"*.sphdigital.com",
"facebook.com",
"*.facebook.net",
"*.facebook.com",
"*.fbcdn.net",
"*.fbsbx.com",
"twitter.com",
"*.twitter.com",
"*.twimg.com",
"*.doubleclick.com",
"*.cxense.com",
"*.adsrvr.org",
"*.colossusssp.com",
"*.ebdr3.com",
"*.crwdcntrl.net",
"*.python.org",
"*.pypi.org",
"*.pythonhosted.org",
"*.githubassets.com",
"*.staruml.io",
"*.kxcdn.com",
"*.hk01.com",
"*.snapchat.com",
"*.app.link",
"*.hotjar.com",
"*.cppreference.com",
"*.voachinese.com",
"*.chartbeat.net",
"*.voanews.com",
"*.githubusercontent.com",
"*.leetcode.com"
]

function checkip(host)
{
    var ipValidate=/^(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$/;
    if( ipValidate.test(host) )
    {
        return true;
    }
    return false;
}

function is_ip_proxy(host)
{
    host_ip = dnsResolve(host)
    if( isInNet(host_ip), "61.112.0.0", "255.255.0.0" ||
        isInNet(host_ip), "61.123.0.0", "255.255.0.0" )
        return true;
    return false;
}

function is_host_proxy(host)
{
    for(var i = 0 ; i < rules.length ; i++)
    {
        if( shExpMatch( host,rules[i] ) )
        {
            return true;
        }
    }
    return false;
}

function FindProxyForURL(url, host) 
{
    if( checkip() )
    {
        if( is_ip_proxy(host) )
            return gfw_proxy;
        else
            return direct;
    }
    else
    {
        if ( is_host_proxy(host) )
            return gfw_proxy
        else
            return direct; 
    }
}