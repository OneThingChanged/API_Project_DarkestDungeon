#include "framework.h"
#include "GameObject.h"
#include "image.h"

GameObject::GameObject()
{
	//m_image = nullptr;
	m_transform = new CTransform();
	m_transform->m_pos = Vector2(0, 0);
	m_transform->m_scale = Vector2(1, 1);
	m_transform->m_pivot = Vector2(0.5, 0.5);
	m_transform->angle = 0;

	m_collider = nullptr;
	m_animator = nullptr;
	m_spriteRenderer = nullptr;

	m_layer = LAYER::Unknown;
	isActive = true;
}
GameObject::~GameObject() {}

HRESULT GameObject::Init()
{
	return S_OK;
}

void GameObject::Update(float deltaTime, float worldTime)
{

}

void GameObject::LateUpdate()
{

}

void GameObject::BackRender(HDC _hdc)
{

}

void GameObject::Render(HDC _hdc)
{

}

void GameObject::FrontRender(HDC _hdc)
{

}

void GameObject::Release()
{
	SAFE_DELETE(m_transform);
	//SAFE_DELETE(m_image);
	SAFE_DELETE(m_collider);
	SAFE_DELETE(m_animator);
	SAFE_DELETE(m_spriteRenderer);
}

void GameObject::AddColliderBox(Vector2 pos, float l, float t, float r, float b)
{
	if (!m_collider)
	{
		m_collider = new CCollider(m_transform);
		m_collider->m_pos = pos;
		m_collider->rect.l = l;
		m_collider->rect.t = t;
		m_collider->rect.r = r;
		m_collider->rect.b = b;
		m_collider->m_colliderType = COLLIDERTYPE::BOX;
	}
	
}

void GameObject::AddColliderBox(float width, float height)
{
	if (!m_collider)
	{
		AddColliderBox(Vector2(0, 0),
			-width * m_transform->m_pivot.x,
			-height * m_transform->m_pivot.y,
			width * (1 - m_transform->m_pivot.x),
			height * (1 - m_transform->m_pivot.y));
	}
	
}

void GameObject::AddColliderBox()
{
	if (!m_collider)
	{
		if (m_spriteRenderer)
		{
			Vector2 imageSize = m_spriteRenderer->GetImageSize();

			AddColliderBox(m_spriteRenderer->pos,
				-imageSize.x * m_transform->m_pivot.x,
				-imageSize.y * m_transform->m_pivot.y,
				+imageSize.x * (1 - m_transform->m_pivot.x),
				+imageSize.y * (1 - m_transform->m_pivot.y));
		}
		else if (m_animator) {
			Vector2 imageSize = m_animator->GetFrameSize();

			AddColliderBox(Vector2(0, 0),
				-imageSize.x * m_transform->m_pivot.x,
				-imageSize.y * m_transform->m_pivot.y,
				+imageSize.x * (1 - m_transform->m_pivot.x),
				+imageSize.y * (1 - m_transform->m_pivot.y));
		}
	}
}

void GameObject::AddColliderBoxBigger()
{
	if (m_spriteRenderer)
	{
		Vector2 imageSize = m_spriteRenderer->GetImageSize();
		if (!m_collider)
		{
			AddColliderBox(m_spriteRenderer->pos,
				-imageSize.x * m_transform->m_pivot.x - 50,
				-imageSize.y * m_transform->m_pivot.y - 50,
				+imageSize.x * (1 - m_transform->m_pivot.x) + 50,
				+imageSize.y * (1 - m_transform->m_pivot.y) + 50);
		}
		else {
			m_collider->SetRect(-imageSize.x * m_transform->m_pivot.x - 50,
				-imageSize.y * m_transform->m_pivot.y - 50,
				+imageSize.x * (1 - m_transform->m_pivot.x) + 50,
				+imageSize.y * (1 - m_transform->m_pivot.y) + 50);
		}
	}
}

void GameObject::AddColliderBoxSmaller()
{
	if (m_spriteRenderer)
	{
		Vector2 imageSize = m_spriteRenderer->GetImageSize();
		if (!m_collider)
		{


			AddColliderBox(m_spriteRenderer->pos,
				-imageSize.x * m_transform->m_pivot.x + 50,
				-imageSize.y * m_transform->m_pivot.y + 50,
				+imageSize.x * (1 - m_transform->m_pivot.x) - 50,
				+imageSize.y * (1 - m_transform->m_pivot.y) - 50);
		}
		else {
			m_collider->SetRect(-imageSize.x * m_transform->m_pivot.x + 50,
				-imageSize.y * m_transform->m_pivot.y + 50,
				+imageSize.x * (1 - m_transform->m_pivot.x) - 50,
				+imageSize.y * (1 - m_transform->m_pivot.y) - 50);
		}
	}
}

void GameObject::AddAnimator(string imageName)
{
	if (!m_animator)
	{
		m_animator = new CAnimator(m_transform);
		m_animator->AddImageFrame(imageName);
	}
	else {
		m_animator->SetTrans(m_transform);
		m_animator->AddImageFrame(imageName);
	}
}

void GameObject::AddAnimator(IMAGE imageName)
{
	if (!m_animator)
	{
		m_animator = new CAnimator(m_transform);
		m_animator->AddImageFrame(imageName);
	}
	else {
		m_animator->SetTrans(m_transform);
		m_animator->AddImageFrame(imageName);
	}
}

void GameObject::AddSpriteRenderer()
{
	if (!m_spriteRenderer)
	{
		m_spriteRenderer = new CSpriteRenderer();
		m_spriteRenderer->SetTrans(m_transform);
	}
	else {
		m_spriteRenderer->SetTrans(m_transform);
	}

}


void GameObject::AddSpriteRenderer(IMAGE imageName)
{
	if (m_spriteRenderer == nullptr)
	{
		m_spriteRenderer = new CSpriteRenderer();
		m_spriteRenderer->SetTrans(m_transform);
		m_spriteRenderer->SetImage(imageName);
	}
	else {
		m_spriteRenderer->SetTrans(m_transform);
		m_spriteRenderer->SetImage(imageName);
	}
}

void GameObject::AddSpriteRenderer(string imageName)
{
	if (!m_spriteRenderer)
	{
		m_spriteRenderer = new CSpriteRenderer();
		m_spriteRenderer->SetTrans(m_transform);
		m_spriteRenderer->SetImage(imageName);
	}
	else {
		m_spriteRenderer->SetTrans(m_transform);
		m_spriteRenderer->SetImage(imageName);
	}
}

void GameObject::Enable()
{
	isActive = true;
}

void GameObject::Disable()
{
	isActive = false;
}