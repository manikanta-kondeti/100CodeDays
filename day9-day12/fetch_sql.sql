create database `login`;
use `login`;
CREATE TABLE `members` (
  `member_id` int(11) unsigned NOT NULL auto_increment,
  `firstname` varchar(100) default NULL,
  `lastname` varchar(100) default NULL,
  `login` varchar(100) NOT NULL default '',
  `passwd` varchar(32) NOT NULL default '',
  PRIMARY KEY  (`member_id`)
);
INSERT INTO `members` VALUES("1", "Jatinder", "Thind", "phpsense", "ba018360fc26e0cc2e929b8e071f052d");
