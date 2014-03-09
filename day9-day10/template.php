
<?php
session_start();

if($_SESSION['SESS_MEMBER_ID']==NULL)
{
	header('Location: login-form.php');
}
