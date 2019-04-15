<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
String path=request.getContextPath(); 
String basePath= request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/"; 
%>
<!DOCTYPE HTML>

<html>
	<head>
	<base href="<%=basePath %>">
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title></title>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<meta name="description" content="" />
	<meta name="keywords" content="" />
	<meta name="author" content="" />
	
  	<!-- Facebook and Twitter integration -->
	<meta property="og:title" content=""/>
	<meta property="og:image" content=""/>
	<meta property="og:url" content=""/>
	<meta property="og:site_name" content=""/>
	<meta property="og:description" content=""/>
	<meta name="twitter:title" content="" />
	<meta name="twitter:image" content="" />
	<meta name="twitter:url" content="" />
	<meta name="twitter:card" content="" />

	<link href="https://fonts.googleapis.com/css?family=Roboto:300,400,700" rel="stylesheet">
	
	<!-- Animate.css -->
	<link rel="stylesheet" href="css/animate.css">
	<!-- Icomoon Icon Fonts-->
	<link rel="stylesheet" href="css/icomoon.css">
	<!-- Themify Icons-->
	<link rel="stylesheet" href="css/themify-icons.css">
	<!-- Bootstrap  -->
	<link rel="stylesheet" href="css/bootstrap.css">

	<!-- Magnific Popup -->
	<link rel="stylesheet" href="css/magnific-popup.css">

	<!-- Owl Carousel  -->
	<link rel="stylesheet" href="css/owl.carousel.min.css">
	<link rel="stylesheet" href="css/owl.theme.default.min.css">

	<!-- Theme style  -->
	<link rel="stylesheet" href="css/style.css">

	<!-- Modernizr JS -->
	<script src="js/modernizr-2.6.2.min.js"></script>
	<!-- FOR IE9 below -->
	<!--[if lt IE 9]>
	<script src="js/respond.min.js"></script>
	<![endif]-->
    <!-- 声明jqure文件代码域 -->
    <script type="text/javascript">
         $(function() {
			//校验密码修改
			$("#fm").submit(function() {
				if($("#newPwd").val()==""){
					//校验新密码
					alert("新密码不能为空");
					return false;
				}else if($("#cfPwd").val()==""){
				    //校验确认密码
					alert("确认密码不能为空");
					return false;
				}else if($("#newPwd").val()!=$("#cfPwd").val()){
					//校验两个是否一致
					alert("两次密码不一致");
					return false;
				}else{
					//确认
					return true;
				}
			})
		})
    </script>
	</head>
	<body>
		
	<div class="gtco-loader"></div>
	
	<div id="page">

	
	<div class="page-inner">
	<nav class="gtco-nav" role="navigation">
		<div class="gtco-container">
			
			<div class="row">
				<div class="col-sm-4 col-xs-12">
					<div id="gtco-logo"><a href="/kwok-ManagementSystem/main/main.jsp">Kwok <em>.</em></a></div>
				</div>
				<div class="col-xs-8 text-right menu-1">
					<ul>
						<li class="btn-cta"><a href="/kwok-ManagementSystem/main/main.jsp"><span>首页</span></a></li>
						<li class="btn-cta"><a href="跳转"><span>修改个人信息</span></a></li>
						<li class="btn-cta"><a href="/kwok-ManagementSystem/user/info.jsp"><span>返回个人信息</span></a></li>
						<li class="btn-cta"><a href="/kwok-ManagementSystem/Login.jsp"><span>退出登录</span></a></li>
					</ul>
				</div>
			</div>
			
		</div>
	</nav>
	
	<header id="gtco-header" class="gtco-cover gtco-cover-sm" role="banner" style="background-image: url(images/img_6.jpg)">
		<div class="overlay"></div>
		<div class="gtco-container">
			<div class="row">
				<div class="col-md-12 col-md-offset-0 text-left">
						<div class="col-md-7 mt-text animate-box" data-animate-effect="fadeInUp">
					<form action="UserServlet" methed="post" id="fm">	
						<input type="hidden" name="oper" value="pwd"/>
						<%
						   //提示语显示判断
			               Object obj2=request.getAttribute("flag1");
						   if("false".equals(obj2)){
						%>
						<li><span style="color:red">密码修改失败</span><li>
						<%} %>
						<ul>
						<li><lable>新密码   </lable><input style="background-color:transparent"name="newPwd" id="newPwd" type="text" class="dfinput"/><i></i></li>
						<li><label>&nbsp;</label><input style="background-color:transparent"name="" type="submit" class="btn-cta" value="确认保存"/></li>
						</ul>
					</form>
						</div>
					</div>
			</div>
		</div>
	</header>
	<div class="gototop js-top">
		<a href="#" class="js-gotop"><i class="icon-arrow-up"></i></a>
	</div>
	
	<!-- jQuery -->
	<script src="js/jquery.min.js"></script>
	<!-- jQuery Easing -->
	<script src="js/jquery.easing.1.3.js"></script>
	<!-- Bootstrap -->
	<script src="js/bootstrap.min.js"></script>
	<!-- Waypoints -->
	<script src="js/jquery.waypoints.min.js"></script>
	<!-- Carousel -->
	<script src="js/owl.carousel.min.js"></script>
	<!-- countTo -->
	<script src="js/jquery.countTo.js"></script>
	<!-- Magnific Popup -->
	<script src="js/jquery.magnific-popup.min.js"></script>
	<script src="js/magnific-popup-options.js"></script>
	<!-- Main -->
	<script src="js/main.js"></script>

	</body>
</html>

