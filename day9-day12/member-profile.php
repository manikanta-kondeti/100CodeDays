<?php
	require_once('auth.php');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>My Profile</title>
<link href="loginmodule.css" rel="stylesheet" type="text/css" />
</head>
<body>
<h1><?php echo "Welcome ".$_SESSION['SESS_FIRST_NAME'];?></h1>
<a href="receptionist-exec.php">Add Patient</a> <br/> 
<a href="logout.php">Logout</a>
<p>This is another secure page. </p>
</body>
</html>
