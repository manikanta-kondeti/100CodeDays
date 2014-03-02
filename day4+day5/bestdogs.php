<?php
include('./fontnames.php');
include('./values/rv1.php');
include('./values/rv2.php');
include('./values/rv3.php');
include('./values/rv4.php');
include('./values/rv5.php');
include('./values/rv6.php');
include('./values/rv7.php');
include('./values/rv8.php');
include('./values/rv9.php');
include('./values/rv10.php');
include('./values/rv11.php');
include('./values/rv12.php');
include('./values/rv13.php');
include('./values/rv14.php');
include('./values/rv15.php');

$index= array();
$ratings1=array();
for($i=1;$i<16;$i++)
{
	$ratings1[$i]=$ratings[$i];
}

for($i=1;$i<16;$i++)
{
	for($j=1;$j<16-$i;$j++)
	{
	
		if($ratings[$j]<$ratings[$j+1])
		{
			//echo $ratings[$j+1];
			
			//swap
			$temp=$ratings[$j];
			$ratings[$j]=$ratings[$j+1];
			$ratings[$j+1]=$temp;
			
		}
	}
}

for($i=1;$i<16;$i++)
{
	for($j=1;$j<16;$j++)
	{
		if($ratings[$i]==$ratings1[$j])
		{
			$index[$i]=$j;
			break;
		}
	}
}
$sum=0;
for($i=1;$i<16;$i++)
{
$sum+=$scores[$i];
}
echo "
<!DOCTYPE html>
<head>
<title>
Best Rating Dogs
</title>
<link href='http://fonts.googleapis.com/css?family=New+Rocker' rel='stylesheet' type='text/css'>
<link href='http://fonts.googleapis.com/css?family=New+Rocker' rel='stylesheet' type='text/css'>

 <link rel='icon' href='./favicon.ico' type='image/x-icon'>
<style>
#image
{
width:200px;
height:200px;
}

#head
{
border : 1px solid blue;
}
</style>
</head>

<body>
<div id='head'>
<br >
<h1 style='font-family: 'New Rocker', cursive;'  align='center' style='position:relative; top:100px;'>

Cute Or Not 
</h1>
</div>


<div align='center'><h3>Total Number Votes : $sum</h3></div>
<div align='center'><h3><a href='http://web.iiit.ac.in/~kondetimanikanta.purushotham/fontmash/'>Main Page</a></h3></div>
<table border='0' align='center'>
<!-- First Dog-->
";
for($i=1;$i<16;$i++)
{
$k=$index[$i];
	echo "
<tr>
<td>
<img id='image' src='images/$k.jpg'></img>

</td>
<td>
<table border='0'>

<tr>
<td>
Dog Name: <b> $name[$k]</b>
</td>
</tr>

<tr>
<td>
Current Rating : <b>$ratings1[$k]</b>
</td>
</tr>


<tr>
<td>
Users Rated : <b>$scores[$k]</b>
</td>
</tr>

</table>
</td>

</tr>
";
}
	?>

<!-- End of one dog-->

</table>

</body>
</html>
