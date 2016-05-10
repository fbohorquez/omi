#!/usr/bin/perl
$global{'count'} = 0;
sub do_cmd_initcn{
   $global{'count'} = 0;
}

sub do_cmd_cn{
   local($_) = @_;
   $global{'count'}  ++;
  sprintf( "%04i", $global{'count'}) . $_;
}
1;
