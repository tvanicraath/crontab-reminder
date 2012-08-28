subject = "reminder"
sendto = "iamrachiit@gmail.com"
msgtxt = "~/reminder/msg.txt"

/bin/mail -s "$subject" - "$sendto" < "$msgtxt"
