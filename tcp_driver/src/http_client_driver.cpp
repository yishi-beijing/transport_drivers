

#include "tcp_driver/http_client_driver.hpp"

#include <iostream>
#include <string>
#include <memory>

//#define WITH_DEBUG_STDCOUT_HTTP_CLIENT_DRIVER // Use std::cout messages for debugging

namespace drivers
{
namespace tcp_driver
{

HttpClientDriver::HttpClientDriver(std::shared_ptr<boost::asio::io_context> ctx)
: m_ctx(ctx)
{
}
HttpClientDriver::~HttpClientDriver()
{
  m_client.reset();
  m_ctx.reset();
}

void HttpClientDriver::init_client(const std::string & ip, uint16_t port)
{
#ifdef WITH_DEBUG_STDCOUT_HTTP_CLIENT_DRIVER
  std::cout << "HttpClientDriver::init_client: " << ip << " : " << port << std::endl;
#endif
  m_client.reset(new HttpClient(m_ctx, ip, port));
}

void HttpClientDriver::init_client(
  const std::string & ip, uint16_t port, uint16_t http_ver)
{
#ifdef WITH_DEBUG_STDCOUT_HTTP_CLIENT_DRIVER
  std::cout << "HttpClientDriver::init_client: " << ip << " : " << port << " : " << http_ver << std::endl;
#endif
  m_client.reset(new HttpClient(m_ctx, ip, port, http_ver));
}


std::shared_ptr<HttpClient> HttpClientDriver::client() const
{
  return m_client;
}

std::string HttpClientDriver::get(const std::string & target)
{
  m_client->get(target);
  return m_client->read_response();
}

std::string HttpClientDriver::post(const std::string & target, const std::string & body)
{
  m_client->post(target, body);
  return m_client->read_result();
}

void HttpClientDriver::asyncGet(Functor func, const std::string & target)
{
  m_client->asyncGet(func, target);
}

void HttpClientDriver::asyncPost(Functor func, const std::string & target, const std::string & body)
{
  m_client->asyncPost(func, target, body);
}

}  // namespace tcp_driver
}  // namespace drivers
