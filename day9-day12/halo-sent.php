
<?php
session_start();

if($_SESSION['SESS_MEMBER_ID']==NULL)
{
	header('Location: login-form.php');
}
else
{

	echo $_POST['id'];
	$id=  $_POST['id'];

}

?>
<html>
<head>
<title>Halo's Sent</title>
<link href="loginmodule.css" rel="stylesheet" type="text/css" />
</head>
<body>
<a style="margin:1000px" href="./logout.php">Logout</a>
<a style="margin:1000px" href="./myhalos.php">Main</a>
<a style="margin:1000px" href="./compose.php">Compose</a>
<?php
$con=mysqli_connect("localhost","root","mysql","login");
// Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$val =$_SESSION['SESS_MEMBER_ID'];
$halo = mysqli_query($con,"SELECT * FROM halo where halo_id=$id");
$rec = mysqli_query($con,"SELECT * FROM receivers where halo_id=$id");

?>
<!-- Halo heading -->
<div>
<?php

while($row= mysqli_fetch_array($halo))
{
	$message=$row['message'];
	$t=$row['t1'];
	$s=$row['sender'];
	echo "<h1 align='center'>$message</h1>";
	echo "<p align='center' style='margin:5px;'><b>Receivers: ";
	$con=mysqli_connect("localhost","root","mysql","login");
	while($nrec=mysqli_fetch_array($rec))
	{
		$k=$nrec['receiver'];
		$name = mysqli_query($con,"SELECT * FROM members where member_id=$k");
		while($n=mysqli_fetch_array($name))
		{ 
			echo $n['login'];
			echo "  ";
		}

	}
	echo "</b></p>";
	echo "<p align='center' style='margin:5px;'><b>$t </b></p>";
}

?>

</div>
<!-- Second table -->
<table border="0" align="center" cellspacing="20">
<thead>
<th>
Responses:
</th>
</thead>

<?php 

$con=mysqli_connect("localhost","root","mysql","login");
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
$threads = mysqli_query($con,"SELECT * FROM thread where halo_id=$id ");
while($th=mysqli_fetch_array($threads))
{
	$uid=$th['user1'];
	$tid=$th['thread_id'];
	$name1 = mysqli_query($con,"SELECT * FROM members where member_id=$uid");
	while($n=mysqli_fetch_array($name1))
	{	 

		echo "<tr><td>";
		$k=$n['login'];
		echo "<form action='chat.php' method='POST'>";
		echo "<input type='hidden' name='halo_id' value='$id'></input>";
		echo "<input type='hidden' name='uid' value='$uid'></input>";
		echo "<input type='hidden' name='name' value='$k'></input>";
		echo "<input type='hidden' name='tid' value='$tid'></input>";
		echo "<input type='submit' name='View' value='$k'></input>";
		echo "</td></tr>";
		echo "</form>";
	}
}

?>


</table>


<!--
<form method='POST' action='messageintodb.php'>
<div align='center'>
<textarea name='message' value=''></textarea>
<input type='submit' value='Send'></input>
<input type='hidden' name='sender' value='$val'> </input>
<input type='hidden' name='receiver' value='$s' ></input>
<input type='hidden' name='thread_id' value='$tid' ></input>
<input type='hidden' name='haloid' value='$id' ></input>
</div>
</form>
-->
</body>
</html>

