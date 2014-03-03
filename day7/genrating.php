<?php
// Replace the spaces in the movie name by hyphens
$yql_base_url = "http://query.yahooapis.com/v1/public/yql";
$movieName=$argv[1];
#print $movieName;
$yql_query="select content from html where url='http://movies.yahoo.com/movie/$movieName' and xpath=\"//span[@class='yom-rating small']//strong[@class='avg-value']\"";
//print $yql_query;
$yql_query_url = $yql_base_url . "?q=" . urlencode($yql_query);  
$yql_query_url .= "&format=json"; 
$session = curl_init($yql_query_url);  
curl_setopt($session, CURLOPT_RETURNTRANSFER,true);      
$jsondata = curl_exec($session);      
//print $jsondata;
$jsondata = "'".$jsondata."'";
#print $jsondata;
$command = "python helper.py " .$movieName ." " .$jsondata ;
#print $command;
$result=system($command);
//echo $result ;
?>
