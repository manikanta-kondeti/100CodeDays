<?php

/**
 * This sample app is provided to kickstart your experience using Facebook's
 * resources for developers. This sample app provides examples of several
 * key concepts, including authentication, the Graph API, and FQL (Facebook
 * Query Language). Please visit the docs at 'developers.facebook.com/docs'
 * to learn more about the resources available to you
 */

// Provides access to app specific values such as your app id and app secret.
// Defined in 'AppInfo.php'
require_once('AppInfo.php');

// Enforce https on production
if (substr(AppInfo::getUrl(), 0, 8) != 'https://' && $_SERVER['REMOTE_ADDR'] != '127.0.0.1') {
header('Location: https://'. $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
exit();
}

// This provides access to helper functions defined in 'utils.php'
require_once('utils.php');


/*****************************************************************************
 *
 * The content below provides examples of how to fetch Facebook data using the
 * Graph API and FQL. It uses the helper functions defined in 'utils.php' to
 * do so. You should change this section so that it prepares all of the
 * information that you want to display to the user.
 *
 ****************************************************************************/

require_once('sdk/src/facebook.php');

$facebook = new Facebook(array(
                        'appId' => AppInfo::appID(),
                        'secret' => AppInfo::appSecret(),
                        'sharedSession' => true,
                        'trustForwarded' => true,
                        ));

$user_id = $facebook->getUser();
if ($user_id) {
        try {
                // Fetch the viewer's basic information
                $basic = $facebook->api('/me');
        } catch (FacebookApiException $e) {
                // If the call fails we check if we still have a user. The user will be
                // cleared if the error is because of an invalid accesstoken
                if (!$facebook->getUser()) {
                        header('Location: '. AppInfo::getUrl($_SERVER['REQUEST_URI']));
                        exit();
                }
        }

        // This fetches some things that you like . 'limit=*" only returns * values.
        // To see the format of the data you are retrieving, use the "Graph API
        // Explorer" which is at https://developers.facebook.com/tools/explorer/
        $likes = idx($facebook->api('/me/likes?limit=0'), 'data', array());


        // This fetches 4 of your friends.
        $friends = idx($facebook->api('/me/friends?limit=5'), 'data', array());

        // And this returns 16 of your photos.
        $photos = idx($facebook->api('/me/photos?limit=0'), 'data', array());

        // Here is an example of a FQL call that fetches all of your friends that are
        // using this app
        $app_using_friends = $facebook->api(array(
                                'method' => 'fql.query',
                                'query' => 'SELECT uid, name FROM user WHERE uid IN(SELECT uid2 FROM friend WHERE uid1 = me()) AND is_app_user = 1'
                                ));


        $threads = $facebook->api(array( 
                                'method'=> 'fql.query', 
                                'query' => 'SELECT thread_id, message_count, recipients FROM thread WHERE folder_id =0 or folder_id =1 ' 
                                ));

}

// Fetch the basic info of the app that they are using
$app_info = $facebook->api('/'. AppInfo::appID());

$app_name = idx($app_info, 'name', '');

?>
<!DOCTYPE html>
<html xmlns:fb="http://ogp.me/ns/fb#" lang="en">
<head>
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=2.0, user-scalable=yes" />

<title>TopChatters</title>
<link rel="shortcut icon" type="image/png" href="./favicon.png"/>
<link rel="stylesheet" href="stylesheets/mobile.css" media="handheld, only screen and (max-width: 480px), only screen and (max-device-width: 480px)" type="text/css" />
<link href='http://fonts.googleapis.com/css?family=Changa+One' rel='stylesheet' type='text/css'>
<!--[if IEMobile]>
<link rel="stylesheet" href="mobile.css" media="screen" type="text/css" />
<![endif]-->

<!-- These are Open Graph tags. They add meta data to your -->
<!-- site that facebook uses when your content is shared -->
<!-- over facebook. You should fill these tags in with -->
<!-- your data. To learn more about Open Graph, visit -->
<!-- 'https://developers.facebook.com/docs/opengraph/' -->
<meta property="og:title" content="<?php echo he($app_name); ?>" />
<meta property="og:type" content="website" />
<meta property="og:url" content="<?php echo AppInfo::getUrl(); ?>" />
<meta property="og:image" content="<?php echo AppInfo::getUrl('/logo.png'); ?>" />
<meta property="og:site_name" content="<?php echo he($app_name); ?>" />
<meta property="og:description" content="App which shows Top Chatters" />
<meta property="fb:app_id" content="<?php echo AppInfo::appID(); ?>" />

<script type="text/javascript" src="/javascript/jquery-1.7.1.min.js"></script>

<script type="text/javascript">
function logResponse(response) {
        if (console && console.log) {
                console.log('The response was', response);
        }
}

$(function(){
                // Set up so we handle click on the buttons
                $('#postToWall').click(function() {
                        FB.ui(
                                {
method : 'feed',
link : $(this).attr('data-url')
},
function (response) {
// If response is null the user canceled the dialog
if (response != null) {
logResponse(response);
}
}
);
                        });

                $('#sendToFriends').click(function() {
                        FB.ui(
                                {
method : 'send',
link : $(this).attr('data-url')
},
function (response) {
// If response is null the user canceled the dialog
if (response != null) {
logResponse(response);
}
}
);
                        });

$('#sendRequest').click(function() {
                FB.ui(
                        {
method : 'apprequests',
message : $(this).attr('data-message')
},
function (response) {
// If response is null the user canceled the dialog
if (response != null) {
logResponse(response);
}
}
);
                });
});
</script>

<!--[if IE]>
<script type="text/javascript">
var tags = ['header', 'section'];
while(tags.length)
        document.createElement(tags.pop());
        </script>
        <![endif]-->
        <style>
        hr
{
color: #f00;
background: #778899;
width: 75%;
height: 5px;
}

#title
{font-family: 'Changa One', cursive;
}
div.img
{
margin:2px;
border:1px solid #0000ff;
height:auto;
width:auto;
float:left;
      text-align:center;
}
div.img img
{
display:inline;
margin:3px;
border:1px solid #ffffff;
}
div.img a:hover img
{
border:1px solid #0000ff;
}
div.desc
{
float: right;
       font-weight:solid;
width:120px;
margin:2px;
       font-color: black;
}
div.welcomebox
{
position:absolute;
top:200px;
left:500px;
}

body
{
        background-image:url('bg.jpg');
        background-size:1700px 850px;
}

</style>
</head>
<body>
<script type="text/javascript">
window.fbAsyncInit = function() {
        FB.init({
appId : '<?php echo AppInfo::appID(); ?>', // App ID
channelUrl : '//<?php echo $_SERVER["HTTP_HOST"]; ?>/channel.html', // Channel File
status : true, // check login status
cookie : true, // enable cookies to allow the server to access the session
xfbml : true // parse XFBML
});

// Listen to the auth.login which will be called when the user logs in
// using the Login button
FB.Event.subscribe('auth.login', function(response) {
                // We want to reload the page now so PHP can read the cookie that the
                // Javascript SDK sat. But we don't want to use
                // window.location.reload() because if this is in a canvas there was a
                // post made to this page and a reload will trigger a message to the
                // user asking if they want to send data again.
                window.location = window.location;
                });

FB.Canvas.setAutoGrow();
};

// Load the SDK Asynchronously
(function(d, s, id) {
 var js, fjs = d.getElementsByTagName(s)[0];
 if (d.getElementById(id)) return;
 js = d.createElement(s); js.id = id;
 js.src = "//connect.facebook.net/en_US/all.js";
 fjs.parentNode.insertBefore(js, fjs);
 }(document, 'script', 'facebook-jssdk'));
</script>



<div id="fb-root"></div>
<script>(function(d, s, id) {
                  var js, fjs = d.getElementsByTagName(s)[0];
                    if (d.getElementById(id)) return;
                      js = d.createElement(s); js.id = id;
                        js.src = "//connect.facebook.net/en_US/all.js#xfbml=1&appId=597433620350029";
                          fjs.parentNode.insertBefore(js, fjs);
                          }(document, 'script', 'facebook-jssdk'));</script>


<?php if (isset($basic)) { ?>

        <?php } else { ?>
                <div class="welcomebox" align="center">
                        <h1 >Top Chatters</h1>
                        <div class="fb-login-button" data-scope="read_mailbox,user_likes,user_photos"></div>

                        
                                        <div id="footer" style="margin-left:100px; margin-top:100px">
                                        <h4> Created, Designed & Developed...Any Suggestions...Contact me : <a href="https://facebook.com/manikanta.kondeti"><b>Manikanta </b></a></h4>
                                        </div>
                        </div>
                        <?php } ?>

                        <style>
                        </style>
                        <?php
                        if ($user_id) {
                                ?>
                                        <h1 id="title" style="font-family: 'Changa One', cursive;  font-color: #C0C0C0;" align="center">My Top Chatters</h1>
                                        <hr>


                                        <?php
                                        $messages=array();
                                $receivers=array();
                                $count=0;
                                foreach($threads as $thread)
                                {
                                        $recipients = idx($thread, 'recipients');
                                        if(count($recipients)==2 )
                                        {
                                                foreach($recipients as $recipient)
                                                {
                                                        if($recipient!=$user_id)
                                                        {
                                                                $receiver=$recipient;
                                                        }
                                                }
                                                $id = idx($thread, 'thread_id');
                                                $message_count = idx($thread, 'message_count');

                                                $messages[$count]=$message_count;
                                                $receivers[$count]=$receiver;
                                                $count+=1;
                                        }

                                }
                                //Sorting the data 

                                for($i=0;$i<$count-1;$i++)
                                {
                                        for($j=0;$j<$count-$i-1;$j++)
                                        {
                                                if($messages[$j]>$messages[$j+1])
                                                {
                                                        $temp1=$messages[$j];
                                                        $messages[$j]=$messages[$j+1];
                                                        $messages[$j+1]=$temp1;

                                                        $temp2=$receivers[$j];
                                                        $receivers[$j]=$receivers[$j+1];
                                                        $receivers[$j+1]=$temp2;

                                                }
                                        }
                                }



                                ?>

                                        <table border="0" align="center" cellspacing="30">
                                        <?php
                                        $flag=19;
                                for($i=$count-1;$i>=0;$i--)
                                {
                                        $id=$receivers[$i];
                                        $flag=$flag-1;
                                        if($flag==0)
                                        {
                                                break;
                                        }
                                        else if($flag%2!=0)
                                        {
                                                ?>
                                                        <td>
                                                        <div>
                                                        <a href="https://www.facebook.com/<?php echo he($id); ?>" target="_top">
                                                        <img src="https://graph.facebook.com/<?php echo he($id) ?>/picture?type=normal" alt="<?php echo he($id); ?>">
                                                        </a>

                                                        <?php echo "Messages: <b>". $messages[$i] ."</b>"; ?>
                                                        </div>
                                                        </td>

                                                        <?

                                        }
                                }
                                ?>
                                        </table>




                                        <header class="clearfix">
                                                        <div id="share-app"  style=" display:inline;" align="center">
                                                        <p>Share your app:</p>
                                                        <ul style=" display: inline;  list-style-type: none;">
                                                        <li>
                                                        <a href="#" class="facebook-button" id="postToWall" data-url="<?php echo "https://topchatters.herokuapp.com/" ?>">
                                                        <span class="plus">Post to Wall</span>
                                                        </a>
                                                        </li>
                                                        <li>
                                                        <a href="#" class="facebook-button speech-bubble" id="sendToFriends" data-url="<?php echo "https://topchatters.herokuapp.com/" ?>">
                                                        <span class="speech-bubble">Send Message</span>
                                                        </a>
                                                        </li>
                                                        <li>
                                                        <a href="#" class="facebook-button apprequests" id="sendRequest" data-message="<non-editable message>">
                                                        <span class="apprequests">Send Requests</span>
                                                        </a>
                                                        </li>
                                                        </ul>
                                                        </div>
                                                        </header>



                                        <div id="footer" style="margin-left:390px; margin-top:100px">
                                        <h4> Created, Designed & Developed...Any Suggestions...Contact me : <a href="https://facebook.com/manikanta.kondeti"><b>Manikanta </b></a></h4>
                                        <div class="fb-like" data-href="https://topchatters.herokuapp.com/" data-layout="standard" data-action="like" data-show-faces="true" data-share="true"></div>
                                        </div>




      <?php
				}
?>
</body>
</html>
