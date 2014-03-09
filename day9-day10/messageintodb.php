
<?php
session_start();

if($_SESSION['SESS_MEMBER_ID']==NULL)
{
	header('Location: login-form.php');
}
echo $_POST['message'];
$con=mysqli_connect("localhost","root","mysql","login");
// Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}


$tid=$_POST['thread_id'];
$sender=$_POST['sender'];
$rec=$_POST['receiver'];
$message=$_POST['message'];

$id=$_POST['haloid'];

echo $sender ;
echo $rec;
mysqli_query($con,"insert into message (thread_id, sender , receiver , message )  values ('$tid' , '$sender' , '$rec' , '$message') ");
?>
<html>
<body>
<?php

echo "<input type='hidden' name='id'  value='$id'></input>";
header('Location: myhalos.php');
?>
</body>
</html>
